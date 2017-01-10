<?php

/**
 *
 * @return boolean
 */
function mobileapi_services_access() {
  return TRUE;
}

/**
 * Return data to session module.
 */
function mobileapi_sessions_services_data() {
  $data = array();

  $data['project_name'] = variable_get('site_name');
  $data['generate_date'] = date('Y-m-d H:i:s');

  $data['sessions_data'] = mobileapi_session_json();
  return $data;
}

/**
 * Sessions data.
 */
function mobileapi_session_json() {
  $json = array();

  $days = session_get_conference_days();
  $rooms = session_get_rooms();
  $sessions_all = sessions_get_sessions_data($days, $rooms);

  // Days.
  foreach($sessions_all as $session_day => $rooms_item) {
    $json_day = array();

    // Rooms.
    foreach($rooms_item as $room_nid => $sessions) {
      $room_name = node_load($room_nid)->title;

      // Sessions.
      foreach ($sessions as $session_nid => $session) {

        //Speakers.
        $speakers_name = mobile_session_speakers($session);
        if (count($speakers_name) > 0) {
          $speakers_name = implode(', ', $speakers_name);
        }
        else {
          $speakers_name = NULL;
        }

        // Time start/end session.
        $time_session = mobile_session_time($session);

        // Language.
        $lang_session = mobile_session_language($session);

        $json_day[] = array(
          'session_name' => $session->title,
          'speakers_name' => $speakers_name,
          'time_start' => $time_session['time_start'],
          'time_end' => $time_session['time_end'],
          'time_start_end' => $time_session['time_start_end'],
          'room' => $room_name,
          'language' => $lang_session,
        );
      }

    }

    // Sort time end.
    mobile_sessions_sort($json_day, 'time_end', SORT_ASC);
    // Sort time start.
    mobile_sessions_sort($json_day, 'time_start', SORT_ASC);

    $json[] = array(
      'day' => $session_day,
      'sessions' => $json_day,
    );
  }

  return $json;
}

/**
 * Session Speakers.
 */
function mobile_session_speakers($session) {
  $speakers_list = array();
  if (isset($session->field_session_speakers[LANGUAGE_NONE][0]['target_id'])) {
    foreach ($session->field_session_speakers[LANGUAGE_NONE] as $speaker) {
      $account = user_load($speaker['target_id']);

      if ($account <> NULL) {
        // First name.
        $first_name = NULL;
        if (isset($account->field_user_first_name[LANGUAGE_NONE][0]['value'])) {
          $first_name = $account->field_user_first_name[LANGUAGE_NONE][0]['value'];
        }

        // Last name.
        $last_name = NULL;
        if (isset($account->field_user_first_name[LANGUAGE_NONE][0]['value'])) {
          $last_name = $account->field_user_last_name[LANGUAGE_NONE][0]['value'];
        }

        // Full name.
        $speakers_list[] = $first_name . ' ' . $last_name;
      }
    }
  }

  return $speakers_list;
}

/**
 * Session time.
 */
function mobile_session_time($session) {
  $time_session = session_get_time_start_and_end($session);

  // Format time.
  $format_hour = 'H:i';

  $time = array();
  $time['time_start'] = date($format_hour, $time_session['timeslot_from']);
  $time['time_end'] = date($format_hour, $time_session['timeslot_to']);
  $time['time_start_end'] = $time['time_start'] . ' - ' . $time['time_end'];

  return $time;
}

/**
 * Session language.
 */
function mobile_session_language($session) {
  $session_language = NULL;
  if (isset($session->field_session_language[LANGUAGE_NONE][0]['value'])) {
    $session_language = $session->field_session_language[LANGUAGE_NONE][0]['value'];
  }

  return $session_language;
}

/**
 * Sort sessions.
 */
function mobile_sessions_sort(&$collection, $index_name, $sort_type = SORT_ASC) {
  $sort = array();

  foreach ($collection as $key => $row) {
    $sort[] = $row[$index_name];
  }

  array_multisort($sort, $sort_type, $collection);
}
