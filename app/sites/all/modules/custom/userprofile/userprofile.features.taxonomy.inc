<?php
/**
 * @file
 * userprofile.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function userprofile_taxonomy_default_vocabularies() {
  return array(
    'tshirt_sizes' => array(
      'name' => 'T-Shirt Sizes',
      'machine_name' => 'tshirt_sizes',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
