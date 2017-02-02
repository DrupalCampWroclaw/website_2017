<?php
/**
 * @file
 * session.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function session_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sessions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sessions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Wykłady';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'więcej';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Przywróć';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_session_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_session_experience_level' => 'field_session_experience_level',
    'field_session_speakers' => 'field_session_speakers',
    'field_session_language' => 'field_session_language',
    'count' => 'count',
    'field_session_type' => 'field_session_type',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = 'count';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_experience_level' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_speakers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_language' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'count' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Nagłówek: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  /* Relationship: Flags: session_vote counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'session_vote';
  /* Relationship: Flags: session_vote */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'session_vote';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Pole: Zawartość: Tytuł */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Pole: Zawartość: Experience level */
  $handler->display->display_options['fields']['field_session_experience_level']['id'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['table'] = 'field_data_field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['field'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['label'] = 'Poziom zaawansowania';
  /* Pole: Zawartość: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['label'] = 'Prelegenci';
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  /* Pole: Zawartość: Session Language */
  $handler->display->display_options['fields']['field_session_language']['id'] = 'field_session_language';
  $handler->display->display_options['fields']['field_session_language']['table'] = 'field_data_field_session_language';
  $handler->display->display_options['fields']['field_session_language']['field'] = 'field_session_language';
  $handler->display->display_options['fields']['field_session_language']['label'] = 'Język';
  /* Pole: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = 'Głosy';
  $handler->display->display_options['fields']['count']['separator'] = ' ';
  /* Pole: Zawartość: Type */
  $handler->display->display_options['fields']['field_session_type']['id'] = 'field_session_type';
  $handler->display->display_options['fields']['field_session_type']['table'] = 'field_data_field_session_type';
  $handler->display->display_options['fields']['field_session_type']['field'] = 'field_session_type';
  $handler->display->display_options['fields']['field_session_type']['label'] = 'Typ';
  $handler->display->display_options['fields']['field_session_type']['exclude'] = TRUE;
  /* Pole: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Głosuj';
  /* Sort criterion: Zawartość: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Zawartość: Opublikowane */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Zawartość: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Propozycje wykładów';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Nagłówek: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<h3><?php print l(t(\'Add session\'),\'node/add/session\') ?></h3>
';
  $handler->display->display_options['path'] = 'sessions/proposed';
  $translatables['sessions'] = array(
    t('Master'),
    t('Wykłady'),
    t('więcej'),
    t('Apply'),
    t('Przywróć'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('counter'),
    t('flag'),
    t('Tytuł'),
    t('Poziom zaawansowania'),
    t('Prelegenci'),
    t('Język'),
    t('Głosy'),
    t('.'),
    t(' '),
    t('Typ'),
    t('Głosuj'),
    t('Page'),
    t('Propozycje wykładów'),
  );
  $export['sessions'] = $view;

  $view = new view();
  $view->name = 'sessions_accepted_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'sessions_accepted_calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'więcej';
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Przywróć';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['id'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['field'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_timeslot_target_id']['id'] = 'field_session_timeslot_target_id';
  $handler->display->display_options['relationships']['field_session_timeslot_target_id']['table'] = 'field_data_field_session_timeslot';
  $handler->display->display_options['relationships']['field_session_timeslot_target_id']['field'] = 'field_session_timeslot_target_id';
  $handler->display->display_options['relationships']['field_session_timeslot_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timeslot_room_target_id']['id'] = 'field_timeslot_room_target_id';
  $handler->display->display_options['relationships']['field_timeslot_room_target_id']['table'] = 'field_data_field_timeslot_room';
  $handler->display->display_options['relationships']['field_timeslot_room_target_id']['field'] = 'field_timeslot_room_target_id';
  $handler->display->display_options['relationships']['field_timeslot_room_target_id']['label'] = 'Content entity referenced from field_timeslot_room';
  /* Pole: Zawartość: Date */
  $handler->display->display_options['fields']['field_timeslot_date']['id'] = 'field_timeslot_date';
  $handler->display->display_options['fields']['field_timeslot_date']['table'] = 'field_data_field_timeslot_date';
  $handler->display->display_options['fields']['field_timeslot_date']['field'] = 'field_timeslot_date';
  $handler->display->display_options['fields']['field_timeslot_date']['label'] = '';
  $handler->display->display_options['fields']['field_timeslot_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_timeslot_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_date']['delta_offset'] = '0';
  /* Pole: Zawartość: Tytuł */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Pole: Zawartość: Room */
  $handler->display->display_options['fields']['field_timeslot_room']['id'] = 'field_timeslot_room';
  $handler->display->display_options['fields']['field_timeslot_room']['table'] = 'field_data_field_timeslot_room';
  $handler->display->display_options['fields']['field_timeslot_room']['field'] = 'field_timeslot_room';
  $handler->display->display_options['fields']['field_timeslot_room']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_room']['settings'] = array(
    'link' => 0,
  );
  /* Pole: Zawartość: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_session_speakers']['label'] = '';
  $handler->display->display_options['fields']['field_session_speakers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  /* Pole: Zawartość: Session Language */
  $handler->display->display_options['fields']['field_session_language']['id'] = 'field_session_language';
  $handler->display->display_options['fields']['field_session_language']['table'] = 'field_data_field_session_language';
  $handler->display->display_options['fields']['field_session_language']['field'] = 'field_session_language';
  $handler->display->display_options['fields']['field_session_language']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_session_language']['label'] = '';
  $handler->display->display_options['fields']['field_session_language']['element_label_colon'] = FALSE;
  /* Pole: Zawartość: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'field_session_timeslot_target_id';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Pole: Zawartość: timeslot_weight */
  $handler->display->display_options['fields']['field_timeslot_weight']['id'] = 'field_timeslot_weight';
  $handler->display->display_options['fields']['field_timeslot_weight']['table'] = 'field_data_field_timeslot_weight';
  $handler->display->display_options['fields']['field_timeslot_weight']['field'] = 'field_timeslot_weight';
  $handler->display->display_options['fields']['field_timeslot_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Pole: Zawartość: room_weight */
  $handler->display->display_options['fields']['field_room_weight']['id'] = 'field_room_weight';
  $handler->display->display_options['fields']['field_room_weight']['table'] = 'field_data_field_room_weight';
  $handler->display->display_options['fields']['field_room_weight']['field'] = 'field_room_weight';
  $handler->display->display_options['fields']['field_room_weight']['relationship'] = 'field_timeslot_room_target_id';
  $handler->display->display_options['fields']['field_room_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_room_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Zawartość: room_weight (field_room_weight) */
  $handler->display->display_options['sorts']['field_room_weight_value']['id'] = 'field_room_weight_value';
  $handler->display->display_options['sorts']['field_room_weight_value']['table'] = 'field_data_field_room_weight';
  $handler->display->display_options['sorts']['field_room_weight_value']['field'] = 'field_room_weight_value';
  $handler->display->display_options['sorts']['field_room_weight_value']['relationship'] = 'field_timeslot_room_target_id';
  /* Sort criterion: Zawartość: timeslot_weight (field_timeslot_weight) */
  $handler->display->display_options['sorts']['field_timeslot_weight_value']['id'] = 'field_timeslot_weight_value';
  $handler->display->display_options['sorts']['field_timeslot_weight_value']['table'] = 'field_data_field_timeslot_weight';
  $handler->display->display_options['sorts']['field_timeslot_weight_value']['field'] = 'field_timeslot_weight_value';
  $handler->display->display_options['sorts']['field_timeslot_weight_value']['relationship'] = 'field_session_timeslot_target_id';
  /* Sort criterion: Zawartość: Date -  start date (field_timeslot_date) */
  $handler->display->display_options['sorts']['field_timeslot_date_value']['id'] = 'field_timeslot_date_value';
  $handler->display->display_options['sorts']['field_timeslot_date_value']['table'] = 'field_data_field_timeslot_date';
  $handler->display->display_options['sorts']['field_timeslot_date_value']['field'] = 'field_timeslot_date_value';
  /* Sort criterion: Zawartość: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'field_session_timeslot_target_id';
  /* Filter criterion: Zawartość: Opublikowane */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '0';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['groupby_times'] = 'half';
  $handler->display->display_options['style_options']['groupby_field'] = 'field_timeslot_room';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Data: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Wszystko';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['date_argument']['default_argument_options']['argument'] = '2014-05-17';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_timeslot_date.field_timeslot_date_value' => 'field_data_field_timeslot_date.field_timeslot_date_value',
  );
  $handler->display->display_options['path'] = 'sessions-accepted-calendar';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['sessions_accepted_calendar'] = array(
    t('Master'),
    t('więcej'),
    t('Apply'),
    t('Przywróć'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Zawartość referencing Zawartość from field_session_timeslot'),
    t('Zawartość entity referenced from field_session_timeslot'),
    t('Content entity referenced from field_timeslot_room'),
    t('Room'),
    t('Post date'),
    t('timeslot_weight'),
    t('room_weight'),
    t('Day'),
    t('Wszystko'),
  );
  $export['sessions_accepted_calendar'] = $view;

  $view = new view();
  $view->name = 'sessions_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sessions user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Submitted sessions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'więcej';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Przywróć';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Pole: Zawartość: Tytuł */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Zawartość: Tytuł */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Zawartość: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Wszystko';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Zawartość: Opublikowane */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Zawartość: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['sessions_user'] = array(
    t('Master'),
    t('Submitted sessions'),
    t('więcej'),
    t('Apply'),
    t('Przywróć'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Wszystko'),
    t('Block'),
  );
  $export['sessions_user'] = $view;

  $view = new view();
  $view->name = 'videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Videos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'więcej';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Przywróć';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Zawartość: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_timeslot_target_id']['id'] = 'field_session_timeslot_target_id';
  $handler->display->display_options['relationships']['field_session_timeslot_target_id']['table'] = 'field_data_field_session_timeslot';
  $handler->display->display_options['relationships']['field_session_timeslot_target_id']['field'] = 'field_session_timeslot_target_id';
  /* Pole: Użytkownik: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Pole: Użytkownik: Last name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_last_name']['element_label_colon'] = FALSE;
  /* Pole: Użytkownik: First name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_user_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_first_name']['element_label_colon'] = FALSE;
  /* Pole: Zawartość: Tytuł */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Pole: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_user_first_name] [field_user_last_name]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Pole: Zawartość: Youtube */
  $handler->display->display_options['fields']['field_youtube']['id'] = 'field_youtube';
  $handler->display->display_options['fields']['field_youtube']['table'] = 'field_data_field_youtube';
  $handler->display->display_options['fields']['field_youtube']['field'] = 'field_youtube';
  $handler->display->display_options['fields']['field_youtube']['label'] = '';
  $handler->display->display_options['fields']['field_youtube']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_youtube']['settings'] = array(
    'video_style' => 'normal',
  );
  /* Sort criterion: Zawartość: Date -  start date (field_timeslot_date) */
  $handler->display->display_options['sorts']['field_timeslot_date_value']['id'] = 'field_timeslot_date_value';
  $handler->display->display_options['sorts']['field_timeslot_date_value']['table'] = 'field_data_field_timeslot_date';
  $handler->display->display_options['sorts']['field_timeslot_date_value']['field'] = 'field_timeslot_date_value';
  $handler->display->display_options['sorts']['field_timeslot_date_value']['relationship'] = 'field_session_timeslot_target_id';
  /* Filter criterion: Zawartość: Opublikowane */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Zawartość: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Zawartość: Status (field_session_status) */
  $handler->display->display_options['filters']['field_session_status_value']['id'] = 'field_session_status_value';
  $handler->display->display_options['filters']['field_session_status_value']['table'] = 'field_data_field_session_status';
  $handler->display->display_options['filters']['field_session_status_value']['field'] = 'field_session_status_value';
  $handler->display->display_options['filters']['field_session_status_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Zawartość: Youtube - Video URL */
  $handler->display->display_options['filters']['field_youtube_video_url']['id'] = 'field_youtube_video_url';
  $handler->display->display_options['filters']['field_youtube_video_url']['table'] = 'field_data_field_youtube';
  $handler->display->display_options['filters']['field_youtube_video_url']['field'] = 'field_youtube_video_url';
  $handler->display->display_options['filters']['field_youtube_video_url']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'videos';
  $translatables['videos'] = array(
    t('Master'),
    t('Videos'),
    t('więcej'),
    t('Apply'),
    t('Przywróć'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('author'),
    t('Zawartość entity referenced from field_session_timeslot'),
    t('[field_user_first_name] [field_user_last_name]'),
    t('Page'),
  );
  $export['videos'] = $view;

  return $export;
}
