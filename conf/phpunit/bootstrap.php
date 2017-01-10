<?php

$current_dir = getcwd();


print "=========== Current dir (/conf/phpunit/bootstrap.php): $current_dir \n";

switch ($current_dir) {
  default:
    $test_host = 'example.com';
  break;
}

print "=========== test_host: $test_host \n";

$_SERVER['REMOTE_ADDR'] = $test_host;
$_SERVER['HTTP_HOST'] = $test_host;

define('DRUPAL_ROOT', $current_dir);
require_once dirname(__FILE__).'/../../app/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
global $base_url;

$base_url = 'http://'.$test_host;

