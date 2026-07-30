# Base image.
FROM debian:bookworm

#Update the system and install Nginx and OpenSSL.
RUN apt update && apt upgrade -y && apt install -y nginx openssl

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4045 \
    -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.crt \
    -subj "/C=ES/ST=Madrid/L=Madrid/O=42/OU=42Madrid/CN=kpineda-.42.fr"

#Copy our custom configuration file into the container.
COPY conf/nginx.conf /etc/nginx/sites-available/default

#Ensure Nginx has the correct permissions for the web files.
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
