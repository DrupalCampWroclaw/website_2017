<?php

/**
 * Settings form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function session_admin_form($form, $form_state) {

  $form['session_submit_end_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Session submit end date'),
    '#description' => t('Format Y-m-d. After this date page node/add/session will be disabled.'),
    '#default_value' => variable_get('session_submit_end_date', '2016-04-30'),
  );

  $form['session_voting_end_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Session voting end date'),
    '#description' => t('Format Y-m-d. After this link in header will be switched to accepted sessions.'),
    '#default_value' => variable_get('session_voting_end_date', '2016-05-07'),
  );

  $form['session_video_link_show_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date when display link to videos'),
    '#description' => t('Format Y-m-d.'),
    '#default_value' => variable_get('session_video_link_show_date', '2016-05-25'),
  );

  return system_settings_form($form);
}