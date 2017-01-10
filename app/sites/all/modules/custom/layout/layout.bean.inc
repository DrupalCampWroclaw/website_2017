<?php
/**
 * @file
 * layout.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function layout_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'simple_block_with_translations';
  $bean_type->label = 'Simple Block With Translations';
  $bean_type->options = '';
  $bean_type->description = 'Simple Block With Translations';
  $export['simple_block_with_translations'] = $bean_type;

  return $export;
}
