<?php
/**
 * @file
 * partners_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function partners_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'partners_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Partners page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partners page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_partner_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Partner website */
  $handler->display->display_options['fields']['field_partner_website']['id'] = 'field_partner_website';
  $handler->display->display_options['fields']['field_partner_website']['table'] = 'field_data_field_partner_website';
  $handler->display->display_options['fields']['field_partner_website']['field'] = 'field_partner_website';
  $handler->display->display_options['fields']['field_partner_website']['label'] = '';
  $handler->display->display_options['fields']['field_partner_website']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_website']['click_sort_column'] = 'url';
  /* Field: Content: Partner logo */
  $handler->display->display_options['fields']['field_partner_logo']['id'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['table'] = 'field_data_field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['field'] = 'field_partner_logo';
  $handler->display->display_options['fields']['field_partner_logo']['label'] = '';
  $handler->display->display_options['fields']['field_partner_logo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_partner_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_partner_logo']['alter']['path'] = '[field_partner_website]';
  $handler->display->display_options['fields']['field_partner_logo']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_partner_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_logo']['settings'] = array(
    'image_style' => '395x197',
    'image_link' => '',
  );
  /* Field: Content: Partner type */
  $handler->display->display_options['fields']['field_partner_type']['id'] = 'field_partner_type';
  $handler->display->display_options['fields']['field_partner_type']['table'] = 'field_data_field_partner_type';
  $handler->display->display_options['fields']['field_partner_type']['field'] = 'field_partner_type';
  $handler->display->display_options['fields']['field_partner_type']['label'] = '';
  $handler->display->display_options['fields']['field_partner_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_type']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Partner type (field_partner_type) */
  $handler->display->display_options['sorts']['field_partner_type_value']['id'] = 'field_partner_type_value';
  $handler->display->display_options['sorts']['field_partner_type_value']['table'] = 'field_data_field_partner_type';
  $handler->display->display_options['sorts']['field_partner_type_value']['field'] = 'field_partner_type_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partners' => 'partners',
  );
  /* Filter criterion: Content: Partner type (field_partner_type) */
  $handler->display->display_options['filters']['field_partner_type_value']['id'] = 'field_partner_type_value';
  $handler->display->display_options['filters']['field_partner_type_value']['table'] = 'field_data_field_partner_type';
  $handler->display->display_options['filters']['field_partner_type_value']['field'] = 'field_partner_type_value';
  $handler->display->display_options['filters']['field_partner_type_value']['value'] = array(
    'supporting_partners' => 'supporting_partners',
  );

  /* Display: Media partners */
  $handler = $view->new_display('page', 'Media partners', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partners' => 'partners',
  );
  /* Filter criterion: Content: Partner type (field_partner_type) */
  $handler->display->display_options['filters']['field_partner_type_value']['id'] = 'field_partner_type_value';
  $handler->display->display_options['filters']['field_partner_type_value']['table'] = 'field_data_field_partner_type';
  $handler->display->display_options['filters']['field_partner_type_value']['field'] = 'field_partner_type_value';
  $handler->display->display_options['filters']['field_partner_type_value']['value'] = array(
    'media_partners' => 'media_partners',
  );
  $handler->display->display_options['path'] = 'partners';
  $handler->display->display_options['menu']['title'] = 'Partners';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $translatables['partners_page'] = array(
    t('Master'),
    t('Partners page'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Media partners'),
    t('Attachment'),
  );
  $export['partners_page'] = $view;

  return $export;
}
