FROM ubuntu:18.04

MAINTAINER Geluchat

RUN useradd -ms /bin/bash magicfish
WORKDIR /home/magicfish

RUN apt-get update
RUN apt-get -y install build-essential xinetd gcc-multilib

COPY magicfish.c /home/magicfish/
COPY flag /home/magicfish/
COPY magicfish_xinetd /etc/xinetd.d/

RUN gcc -m32 -no-pie -Wl,-z,relro,-z,now magicfish.c -o /home/magicfish/magicfish
RUN chmod 555 /home/magicfish
RUN chown root:root -R /home/magicfish/
RUN chmod 444 /home/magicfish/*
RUN chmod +x /home/magicfish/magicfish

COPY run.sh /
RUN chmod +x /run.sh

EXPOSE 5555

CMD ["/run.sh"]