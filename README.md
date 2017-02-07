website DrupalCamp Wrocław
============================

Strona internetowa  DrupalCamp Wrocław.

Strona konferencji www.drupalcampwroclaw.pl

Zmiany w repo wprowadzamy w branchu "develop", zgodnie z git flow
- https://github.com/nvie/gitflow
- http://nvie.com/posts/a-successful-git-branching-model/

Strona to profil instalacyjny oparty o platformę Drupala.
W pliku /docs/developer-info.txt instrukcja jak zainstalować stronę na serwerze linuksowym, wymagany Drush.
Do katalogu /conf/local skopiuj pliki z /conf/template i zmień w plikach parametry zależnie od ustawień swojego serwera.
Style do szablonu piszemy w plikach scss (SASS http://sass-lang.com/)
Używamy Zen Grids http://zengrids.com/

Jeśli chcesz pomóc w rozwoju strony i otrzymać uprawnienia do repozytorium GIT pisz na adres info@drupalcampwroclaw.pl lub w https://github.com/DrupalCampWroclaw/website/issues

Sprawy organizacyjne konferencji: https://github.com/DrupalCampWroclaw/organizacyjne/issues

Organizatorzy konferencji: https://github.com/DrupalCampWroclaw?tab=members

----------------------------


* nginx proxy for docker required
* install docker-console https://github.com/droptica/docker-console 
* * sudo apt-get update && sudo apt-get -y install python-yaml python-setuptools python-pip python-dev build-essential
* * sudo pip install docker-console
* git clone https://github.com/DrupalCampWroclaw/website_2017_wrapper_docker_console.git drupalcamp
* cd drupalcamp
* git clone https://github.com/DrupalCampWroclaw/website_2017.git app
* copy database.sql.tar.gz dump to /app_databases/
* copy files.tar.gz to /app_files/
* add to /etc/hosts
* * 127.0.0.1 drupalcamp.dev www.drupalcamp.dev phpmyadmin.drupalcamp.dev 
* docker-console up
* docker-console build
