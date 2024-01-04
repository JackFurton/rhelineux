#!/usr/bin/env bash
docker system prune -a && docker volume prune -a
docker build . -t valgrind
docker run -ti valgrind:latest
