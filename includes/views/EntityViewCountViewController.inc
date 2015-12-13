<?php

/**
 * @file
 * Provides support for the Views module.
 */

/**
 * "Entity view count" entity Views definition.
 */
class EntityViewCountViewController extends EntityDefaultViewsController {

  /**
   * Override views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    $data['entity_view_count']['created']['field']['handler'] = 'views_handler_field_date';

    return $data;
  }
}
