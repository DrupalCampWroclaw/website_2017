<?php
/**
 * @file
 * sponsor.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sponsor_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sponsors';
  $context->description = '';
  $context->tag = 'sponsors';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sponsors' => 'sponsors',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-sponsor-text' => array(
          'module' => 'bean',
          'delta' => 'sponsor-text',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('sponsors');
  $export['sponsors'] = $context;

  return $export;
}
