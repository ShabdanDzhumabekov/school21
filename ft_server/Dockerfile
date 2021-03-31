FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install wget

RUN apt-get -y install vim
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server

WORKDIR /var/www/html/
RUN rm index.nginx-debian.html
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

COPY ./srcs/init_container.sh ./
COPY ./srcs/default /etc/nginx/sites-available/
COPY ./srcs/config.inc.php phpmyadmin
COPY ./srcs/wp-config.php ./wordpress/


RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Rush/L=Kazan/O=school21/OU=shaba" -newkey rsa:2048 -keyout /etc/ssl/shaba.key -out /etc/ssl/shaba.crt;

RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

CMD bash init_container.sh