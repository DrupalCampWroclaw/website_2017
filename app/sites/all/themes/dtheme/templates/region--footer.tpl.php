<?php
/**
 * @file
 * Returns the HTML for the footer region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<?php if ($content): ?>
  <footer id="footer" class="<?php print $classes; ?>">
    <div id="footer-inner">
      <?php print $content; ?>
      <div id="page-bottom-links-over">
        <div id="page-bottom-links" class="block">
          <ul>
            <li>
              <a href="https://github.com/DrupalCampWroclaw" target="_blank">DrupalCamp Wroclaw on GitHub</a>
            </li>
            <li>
              <a href="http://2015.drupalcampwroclaw.pl/" target="_blank">DrupalCamp Wroclaw 2015</a>
            </li>
            <li>
              <a href="http://2014.drupalcampwroclaw.pl/" target="_blank">DrupalCamp Wroclaw 2014</a>
            </li>
            <li>
              <a href="http://2013.drupalcampwroclaw.pl/" target="_blank">DrupalCamp Wroclaw 2013</a>
            </li>
            <li>
              <a href="http://2012.drupalcampwroclaw.pl/" target="_blank">DrupalCamp Wroclaw 2012</a>
            </li>
          </ul>
          <ul>
            <li>
              <a href="http://www.drupalday.pl/" target="_blank">DrupalDay</a>
            </li>
            <li>
              <a href="http://www.drupalidzienastudia.pl/" target="_blank">Drupal idzie na studia </a>
            </li>
            <li>
              <a href="https://groups.drupal.org/poland" target="_blank">Drupal Groups - Poland</a>
            </li>
          </ul>
        </div>
      </div>
    </div>
    </div>

  </footer>
<?php endif; ?>
