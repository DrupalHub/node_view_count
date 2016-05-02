<?php

class entity_view_count_cache_sort_handler_view_count extends views_handler_sort {
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['sort_style'] = array(
      '#type' => 'select',
      '#title' => t('Sorting type'),
      '#description' => t('Determine how you would like to sort the results'),
      '#options' => array(
        'default' => t('Order by the time the entity was viewed.'),
      ),
      '#default_value' => $this->options['sort_style'],
    );
    if ($this->view->base_table == 'users') {
      $form['sort_style']['#options']['user_viewing_entities'] = t('Order by the number of times the user viewed entities.');
      $form['sort_style']['#options']['user_viewed_entities'] = t('Order by the number of the user entity\'s viewed.');
    }

    $options = array();

    foreach (entity_get_info() as $key => $info) {
      if (!$info['fieldable']) {
        continue;
      }

      $options[$key] = $info['label'];
    }

    $form['entity_type'] = array(
      '#type' => 'select',
      '#title' => t('Entity type'),
      '#description' => t('You need to provide the entity type for th order.'),
      '#options' => $options,
      '#default_value' => $this->options['entity_type'],
    );

    $form['#attached']['js'][] = drupal_get_path('module', 'entity_view_count') . '/includes/entity_view_count.js';
  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['sort_style'] = array('default' => 'default');
    $options['entity_type'] = array('default' => '');

    return $options;
  }

  /**
   * Overrides parent::query().
   */
  public function query() {
    $this->ensure_my_table();

    $this->query->orderby[] = array(
      'field' => "(SELECT count FROM `entity_view_count_cache` WHERE (entity_id = " . $this->view->base_table . "." . $this->view->base_field . " and entity_type = '" . $this->options['entity_type'] . "'))",
      'direction' => $this->options['order'],
    );

  }

}
