FROM --platform=linux/amd64 ubuntu:latest

RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    valgrind \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app