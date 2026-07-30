#!/bin/sh
echo "--- EL SCRIPT DE CONFIGURACION HA EMPEZADO ---"

#Read passwords.
if [ -f "/run/secrets/db_password" ]; then
    MYSQL_PASSWORD=$(cat /run/secrets/db_password)
fi
if [ -f "/run/secrets/db_root_password" ]; then
    MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
fi

#Only initialize if no data actually exists.
if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

#Start the server temporarily.
mysqld_safe --datadir='/var/lib/mysql' &
sleep 5

#Always configure.
mysql -u root -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
mysql -u root -e "CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -u root -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%';"
mysql -u root -e "FLUSH PRIVILEGES;"

#Stop the server temporarily.
mysqladmin -u root shutdown
sleep 2

echo "--- CONFIGURACION FINALIZADA ---"
exec mysqld_safe --datadir='/var/lib/mysql'
