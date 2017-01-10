<div id="sessions-links">
  <ul>

    <?php if($is_session_submit_active):?>
      <li><?php print l(t('Submit a Session'), 'node/add/session'); ?></li>
      <li><?php print l(t('Proposed Sessions'), 'sessions/proposed'); ?></li>
    <?php endif; ?>

    <?php if(!$is_session_submit_active && $is_session_voting_active):?>
      <li><?php print l(t('Proposed Sessions'), 'sessions/proposed'); ?></li>
    <?php endif; ?>

    <?php if(!$is_session_submit_active && !$is_session_voting_active):?>
      <li><?php print l(t('Accepted Sessions'), variable_get('conferencestats_node_accepted', 'node/70')); ?></li>
      <li><?php print l(t('Proposed Sessions'), 'sessions/proposed'); ?></li>
    <?php endif; ?>

    <?php if($is_video_link_active):?>
      <li><?php print l(t('Videos'), 'videos'); ?></li>
    <?php endif; ?>

  </ul>
</div>
