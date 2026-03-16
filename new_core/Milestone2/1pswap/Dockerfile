# FROM --platform=linux/amd64 ubuntu:latest

# RUN apt-get update && apt-get install -y \
#     build-essential \
#     clang \
#     valgrind \
#     git \
#     && rm -rf /var/lib/apt/lists/*

# WORKDIR /app

# We remove the --platform flag to let it default to your native arm64
FROM ubuntu:latest

# Avoid prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    valgrind \
    git \
    cmake \
    libx11-dev \
    libxext-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
	file \
	tree \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Optional: Add a bash alias to make testing easier
RUN echo "alias ptest='ARG=\$(seq 1 500 | shuf | xargs); ./push_swap \$ARG | ./checker_bonus \$ARG'" >> ~/.bashrc

CMD ["bash"]