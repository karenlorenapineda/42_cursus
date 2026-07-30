#!/bin/sh

#Enable debug mode to display commands in docker-compose logs.
set -x

#1. Read the password from Docker Secrets if the file exists.
if [ -f "/run/secrets/db_password" ]; then
    export MYSQL_PASSWORD=$(cat /run/secrets/db_password)
fi

#2. Ensure MariaDB is ready.
sleep 10

#3. Check whether WordPress is already installed.
if [ ! -f "/var/www/wordpress/wp-config.php" ]; then
    
    mkdir -p /var/www/wordpress
    cd /var/www/wordpress
    
    # Download WP-CLI if it is not already installed.
    if [ ! -f "/usr/local/bin/wp" ]; then
        curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
        chmod +x wp-cli.phar
        mv wp-cli.phar /usr/local/bin/wp
    fi
    
    # Download the WordPress files.
    wp core download --allow-root
    
    # Create the `wp-config.php` file.
    wp config create \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${MYSQL_PASSWORD}" \
        --dbhost=mariadb \
        --allow-root
    
    # Install WordPress
    wp core install \
        --url="${DOMAIN_NAME}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email \
        --allow-root

    # Create the required author user.
    wp user create \
        "${WP_USER}" \
        "${WP_USER_EMAIL}" \
        --user_pass="${WP_PASSWORD}" \
        --role=author \
        --allow-root
fi

# Set the correct permissions for the web server (required for PHP-FPM to work properly).
chown -R www-data:www-data /var/www/wordpress

#Create the PHP log directory if it does not exist.
mkdir -p /run/php

#Start PHP-FPM in the foreground.
exec /usr/sbin/php-fpm8.2 -F
