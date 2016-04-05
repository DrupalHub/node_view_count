<?php

function entity_view_count_cache_views_data_alter(&$data) {
  $data['node']['entity_views_cache'] = array(
    'group' => 'Entity views cache',
    'title' => t('View count sorting'),
    'help' => t('This provides an sorting on view counts'),
    'sort' => array(
      'handler' => 'entity_view_count_cache_sort_handler_view_count',
    ),
  );
  $data['users']['entity_views_cache'] = array(
    'group' => 'Entity views cache',
    'title' => t('View count sorting'),
    'help' => t('This provides an sorting on view counts'),
    'sort' => array(
      'handler' => 'entity_view_count_cache_sort_handler_view_count',
    ),
  );
}
