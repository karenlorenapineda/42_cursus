#Debian Bookworm as the universal base for the project.
FROM debian:bookworm

#Update the package lists and install the MariaDB server. 
RUN apt update && apt upgrade -y && apt install -y mariadb-server

#Create the secure runtime directory for the MariaDB socket and set the appropriate permissions.
RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && chmod 777 /var/run/mysqld

#Copy our custom network configuration.
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

#Copy the setup script and make it executable.
COPY tools/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

#Expose the default MySQL/MariaDB database port.
EXPOSE 3306

#Set the setup script as the entry point that starts the service.
ENTRYPOINT ["/usr/local/bin/setup.sh"]
