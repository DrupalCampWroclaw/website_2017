<?php
// $Id: $

$_SERVER['REMOTE_ADDR'] = 'example.com';
$_SERVER['HTTP_HOST'] = 'example.com';

$current_dir = getcwd();
define('DRUPAL_ROOT', $current_dir);

if (!isset($test_host)) {
  $test_host = 'example.com';
}

print "=========== Current dir (phpunit_drupal.php): $current_dir \n";
print "=========== test_host: $test_host \n";

$_SERVER['REMOTE_ADDR'] = $test_host;
$_SERVER['HTTP_HOST'] = $test_host;

/**
 * @file
 * PHPunit helper functions for Drupal tests.
 * Drupal 7
 *
 * Author: grzegorz.bartman@openbit.pl
 * Version: 3.1fresh
 */
require_once 'includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

abstract class PHPUnit_Drupal extends PHPUnit_Framework_TestCase {

  protected $time, $nodesList, $usersList, $commentsList, $variables;
  protected $database;

  function __construct() {
    $this->time = time();
  }

  function __destruct() {
    //Remove test comments
    if (isset($this->commentsList)) {
      foreach ($this->commentsList as $cid) {
        $this->commentDelete($cid);
      }
    }

    //Remove test nodes
    if (isset($this->nodesList)) {
      foreach ($this->nodesList as $node) {
        $this->nodeDelete($node);
      }
    }

    //Remove test users
    if (isset($this->usersList)) {
      foreach ($this->usersList as $uid) {
        $this->userDelete($uid);
      }
    }

    // Restore variables.
    if (isset($this->variables)) {
      foreach ($this->variables as $name => $value) {
        variable_set($name, $value);
      }
    }

    // Remove test terms
    if (isset($this->terms)) {
      foreach ($this->terms as $tid) {
        taxonomy_del_vocabulary($vid);
      }
    }

    // Remove test vocabularies
    if (isset($this->vacabularies)) {
      foreach ($this->vocabularies as $vid) {
        taxonomy_del_vocabulary($vid);
      }
    }
  }

  public function setUp() {
    global $db_url;

    if (is_array($db_url)) {
      $url = parse_url($db_url['default']);
    }

    elseif (!is_array($db_url)) {
      $url = parse_url($db_url);
    }

    $this->database = substr($url['path'], 1);
  }

  public function tearDown() {

  }

  /**
   * Display debug information
   * @param $name
   *  Title
   * @param $variable
   *  Variable to display in print_r() function
   */
  protected function displayDebug($name, $variable) {
    print '
        ' . $name . ':
        ';
    print_r($variable);
    print '
        Memory usage:' . (memory_get_usage() / 1024 / 1024) . ' MB
        ';
    print '
        Time: ' . (time() - $this->time) . ' seconds
        ';
  }



  /**
   * Set variable. All variables are restored after tests.
   *
   * @param $name
   *   Variable name.
   * @param $value
   *   Variable value.
   */
  protected function variableSet($name, $value) {
    $deafult = '';
    if (!isset($this->variables[$name])) {
      $this->variables[$name] = variable_get($name, $default);
    }
    variable_set($name, $value);
  }

  /**
   * Get variable.
   *
   * @param $name
   *   Variable name.
   * @param $default
   *  Default value.
   *
   * @return
   *   Variable value.
   */
  protected function variableGet($name, $default) {
    return variable_get($name, $default);
  }

  /**
   * Check is column in table in database.
   *
   * @param $table
   *   Table name.
   * @param $column
   *   Column name.
   * @param $database
   *   Database name.
   *
   * @return
   *   TRUE if column exists.
   */
  protected function isColumnInTable($table, $column, $database) {
    db_unlock_tables();
    $count = db_result(db_query("SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS
          WHERE TABLE_NAME = '%s'
          AND COLUMN_NAME = '%s'
          AND TABLE_SCHEMA = '%s'", $table, $column, $database));
    return 1 == $count;
  }

  /**
   * Check database tables.
   */
  protected function checkTables($array, $database) {
    foreach ($array as $table => $columns) {
      foreach ($columns as $column) {
        $this->assertEquals(TRUE, $this->isColumnInTable($table, $column, $database));
      }
    }
  }



}
