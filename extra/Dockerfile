FROM ubuntu:latest

WORKDIR /app

RUN apt update && apt upgrade -y && \
    apt install -y vim \
    build-essential -y \
    valgrind -y

COPY vimrc /root/.vimrc

COPY . /app
