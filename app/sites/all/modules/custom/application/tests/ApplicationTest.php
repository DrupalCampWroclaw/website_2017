<?php

// $Id$

/**
 * @file
 * PHPunit tests
 */
//Include Drupal PHPunit helper functions
require_once 'sites/all/phpunit/phpunit_drupal.php';

/**
 * Test class.
 */
class ApplicationTest extends PHPUnit_Drupal {

  public function setUp() {
    // Set language.
    $languages = language_list();
    global $language;
    $language = $languages['en'];
  }

  public function testFeaturesDefault() {

    global $language;
    print "\n";
    $features = application_features_list();
    module_load_include('inc', 'features', 'features.export');
    print "Test features state 0 = FEATURES_DEFAULT, 1 = FEATURES_OVERRIDDEN, 2=FEATURES_NEEDS_REVIEW \n";
    foreach ($features as $feature_name) {

      // Load informations about feature.
      $states = features_get_component_states($features = array($feature_name), FALSE, $reset = TRUE);

      $states_feature = reset($states);
      $status = FEATURES_DEFAULT; // 0
      foreach ($states_feature as $key => $item) {
        if ($item != FEATURES_DEFAULT) {
          $status = FEATURES_OVERRIDDEN;
          print 'Overriden component name: ' . $key . " \n";
          break;
        }
      }

      print "Test features default: $feature_name status: $status  [language: " . $language->language . " ]\n";
      $this->assertEquals(0, $status);
    }
  }

  public function testModulesEnabled() {

    print "\n";
    $modules = application_features_list();
    $modules[] = 'dblog';

    foreach ($modules as $modules_name) {
      $result = module_exists($modules_name);
      print "Test module enabled: {$result} [$modules_name]\n";
      $this->assertEquals(TRUE, module_exists($modules_name));
    }
  }

  public function testModulesDisabled() {
    print "\n";
    $modules = array();
    $modules[] = 'devel';
    $modules[] = 'coder';
    $modules[] = 'overlay';
    $modules[] = 'toolbar';

    foreach ($modules as $modules_name) {
      if (module_exists($modules_name)) {
        $result = 0;
      }
      else {
        $result = 1;
      }

      print "Test module disabled: {$result} [$modules_name] \n";
      $this->assertEquals(FALSE, module_exists($modules_name));
    }
  }
}
