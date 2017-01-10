<?php

/**
 * Settings form.
 */
function conferencestats_admin_form($form, $form_state) {

  $form['conferencestats_start_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Conference start date'),
    '#description' => t('Format Y-m-d. Used in header conference stats. After this date time left will be disabled.'),
    '#default_value' => variable_get('conferencestats_start_date', '2015-05-29'),
  );

  return system_settings_form($form);
}