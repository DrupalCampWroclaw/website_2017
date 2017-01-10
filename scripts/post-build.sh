echo "==================="
echo "Post-build script start"

# Add custom code here
# for example: enable initcontent module

drush -r $PARAM_PROJECT_PATH_APP dis coder devel -y

drush -r $PARAM_PROJECT_PATH_APP en stage_file_proxy -y
drush -r $PARAM_PROJECT_PATH_APP rr
drush -r $PARAM_PROJECT_PATH_APP variable-set stage_file_proxy_origin "http://www.drupalcampwroclaw.pl"

echo "Post-build script end"
echo "==================="
