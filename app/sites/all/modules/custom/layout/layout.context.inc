<?php
/**
 * @file
 * layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function layout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage';
  $context->description = '';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'layout-frontpage_top' => array(
          'module' => 'layout',
          'delta' => 'frontpage_top',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-sponsors_frontpage_block-block' => array(
          'module' => 'views',
          'delta' => 'sponsors_frontpage_block-block',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'views-8b25923f8a8f31d204c26febe72e3b65' => array(
          'module' => 'views',
          'delta' => '8b25923f8a8f31d204c26febe72e3b65',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'views-c29026ea424da992d018da7a9cbfe178' => array(
          'module' => 'views',
          'delta' => 'c29026ea424da992d018da7a9cbfe178',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'views-people-block_1' => array(
          'module' => 'views',
          'delta' => 'people-block_1',
          'region' => 'footer',
          'weight' => '-7',
        ),
        'layout-social_facebook_gplus_twitter' => array(
          'module' => 'layout',
          'delta' => 'social_facebook_gplus_twitter',
          'region' => 'footer',
          'weight' => '-6',
        ),
        'flickr-flickr' => array(
          'module' => 'flickr',
          'delta' => 'flickr',
          'region' => 'footer',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  $export['frontpage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_add_session';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/add/session' => 'node/add/session',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['node_add_session'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sessions_proposed';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sessions/proposed' => 'sessions/proposed',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-proposed-sessions-text' => array(
          'module' => 'bean',
          'delta' => 'proposed-sessions-text',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sessions_proposed'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'sitewide';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'layout-main_menu' => array(
          'module' => 'layout',
          'delta' => 'main_menu',
          'region' => 'navigation',
          'weight' => '-9',
        ),
        'views-sponsors_diamond_block-block' => array(
          'module' => 'views',
          'delta' => 'sponsors_diamond_block-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'layout-sessions' => array(
          'module' => 'layout',
          'delta' => 'sessions',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean-important-dates' => array(
          'module' => 'bean',
          'delta' => 'important-dates',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('sitewide');
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-sessions_user-block' => array(
          'module' => 'views',
          'delta' => 'sessions_user-block',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['user_profile'] = $context;

  return $export;
}
