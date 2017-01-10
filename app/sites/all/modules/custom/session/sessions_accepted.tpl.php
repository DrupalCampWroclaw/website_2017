<?php

$rooms_count = 0;
$columns = 12;

$output = '';

foreach ($data as $day => $rooms) {


  $day_start = strtotime(date($day));

  $column_class = $columns / count($rooms);



  $output .= '<div class="sessions-accepted sessions-accepted-day clearfix">';
  $output .= '<h2 class="day">' . $day . '</h2>';

  //$param_height = 0.072;
  static $test;
  $param1 = 1.4;
  $param_time_to_pixel = 50;
  $param_top_minus_10hours = 36000;

  foreach ($rooms as $room_nid => $sessions) {
    // Calculate max height.
    // Get last time end.
    $max_height = 0;
    foreach ($sessions as $session_nid => $session) {
      $time_start_end = session_get_time_start_and_end($session);
      $last_timeslot_end_time = $time_start_end['timeslot_to'];
    }

    $max_height  = round(($last_timeslot_end_time - $day_start -$param_top_minus_10hours)/$param_time_to_pixel * $param1) + 40;

    // Display room name.
    $output .= '<div class="sessions-accepted-room clearfix columns-' . $column_class . '" style="height:'.$max_height.'px;">';
    $output .= '<div class="inner">';
    $output .= '<h3 class="room-name">' . node_load($room_nid)->title . '</h3>';
    $output .= '<div class="sessions-list">';


    $i = 0;



    foreach ($sessions as $session_nid => $session) {

      $time_start_end = session_get_time_start_and_end($session);

      $format_hour = 'H:i';

      $time_start_end_string = ' ' . date($format_hour,$time_start_end['timeslot_from']) . ' - ' . date($format_hour,$time_start_end['timeslot_to']);

      $time_diff = $time_start_end['timeslot_to'] - $time_start_end['timeslot_from'];

      $time_height_param = round($time_diff/$param_time_to_pixel * $param1);

      $time_top_param = round((($time_start_end['timeslot_from'] - $day_start) - $param_top_minus_10hours)/$param_time_to_pixel * $param1) ;


      // Get speakers.

      $speakers_string = '';
      $speakers_list = array();
      if (isset($session->field_session_speakers['und'][0]['target_id'])) {
        foreach ($session->field_session_speakers['und'] as $speaker) {
          $account = user_load($speaker['target_id']);

          $full_name = $account->field_user_first_name['und'][0]['value'] . ' ' .$account->field_user_last_name['und'][0]['value'];

          $speakers_list[] = '<span class="session-speaker">'.l($full_name, 'user/' . $speaker['target_id']).'</span>';
        }
      }

      $speakers_string = implode(', ', $speakers_list);

      // Get language.
      $session_lang = $session->field_session_language['und'][0]['value'];

      $max_title_length = 50;
      if (drupal_strlen($session->title) > $max_title_length) {
        $session_title = drupal_substr($session->title, 0, $max_title_length) . '...';
      }
      else {
        $session_title = $session->title;
      }


      $output .= '<div class="sessions-accepted-session" style="height: ' . $time_height_param . 'px; top: ' . $time_top_param . 'px; ">';
      $output .= '    <div class="inner">';
      $output .= '        <div class="session-accepted-session-time">' . $time_start_end_string . '</div>';
      $output .= '        <div class="session-accepted-session-title">'. l($session_title, 'node/' . $session->nid) . ' ['.$session_lang.']</div>';
      $output .= '        <div class="session-accepted-session-speakers">' . $speakers_string . '</div>';
      $output .= '    </div>';
      $output .= '</div>';

    }
    $output .= '</div></div></div>';
  }

  $output .= '</div>';
}

print $output;

