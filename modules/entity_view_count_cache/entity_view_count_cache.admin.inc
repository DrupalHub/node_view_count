<?php

/**
 * Reindex form
 * @param $form
 * @param $form_state
 * @return mixed
 */
function entity_view_count_cache_reindex_form($form, $form_state) {
  $count = db_query("SELECT COUNT(DISTINCT entity_id, entity_type, entity_owner) AS count FROM {entity_view_count}")->fetchField();
  $count2 = db_query("SELECT COUNT(id) AS count FROM {entity_view_count_cache}")->fetchField();


  $form['indexed_items'] = array(
    '#markup' => t('There are @count items indexed', array('@count' => $count2)) . '<br />',
  );
  $form['not_indexed_items'] = array(
    '#markup' => t('There are @count missing indexed items', array('@count' => $count - $count2)) . '<br /> <br />',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Reindex'),
  );

  return $form;
}

/**
 * Submit reindex form
 */
function entity_view_count_cache_reindex_form_submit() {
  entity_view_count_cache_update_batch();
}
