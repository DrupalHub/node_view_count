<?php

/**
 * @file
 * Holds all that relate to field api.
 *
 * Although this is not a normal field we need an easy way to display
 * information about the given entity. Create field that will return the value
 * of the views is the right solution for that.
 */

/**
 * Implements hook_field_formatter_info().
 */
function entity_view_count_cache_field_formatter_info() {
  return array(
    'default_cache' => array(
      'label' => t('Entity view count cache default'),
      'field types' => array('entity_view_count'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function entity_view_count_cache_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  if (!user_access('view entity view count field')) {
    return array();
  }

  $wrapper = entity_metadata_wrapper($entity_type, $entity);

  switch ($display['type']) {
    case 'default':
    default:
      $result = entity_view_count_cache_get_entity_count($entity_type, $wrapper->getIdentifier());
      break;
  }

  return array(
    '0' => array('#markup' => $result),
  );
}
