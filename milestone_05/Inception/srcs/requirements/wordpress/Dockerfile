#Debian Bookworm as the base image.
FROM debian:bookworm

#Update the package lists and install the required dependencies.
RUN apt update && apt upgrade -y && apt install -y \
    php8.2 \
    php8.2-fpm \
    php8.2-mysql \
    mariadb-client \
    curl \
    sendmail \
    && rm -rf /var/lib/apt/lists/*

#Configure PHP-FPM to listen on port 9000
#(required for communication with Nginx).
RUN sed -i 's/listen = \/run\/php\/php8.2-fpm.sock/listen = 9000/g' /etc/php/8.2/fpm/pool.d/www.conf

#Create the required directories.
RUN mkdir -p /var/www/wordpress
RUN mkdir -p /run/php

#Copy our setup script.
COPY tools/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

# Expose port 9000
EXPOSE 9000

#The setup script is responsible for configuring WordPress and starting PHP-FPM.
ENTRYPOINT ["/usr/local/bin/setup.sh"]
