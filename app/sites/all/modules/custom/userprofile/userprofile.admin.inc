<?php

/**
 * Settings form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function userprofile_admin_form($form, $form_state) {

  $form['userprofile_planned_attendance_show_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date when display "Planned attendance" on user profile page'),
    '#description' => t('Format Y-m-d.'),
    '#default_value' => variable_get('userprofile_planned_attendance_show_date', '2015-04-30'),
  );

  return system_settings_form($form);
}