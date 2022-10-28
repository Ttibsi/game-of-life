FROM ubuntu:jammy

# hadolint ignore=DL3008
RUN apt-get update && apt-get upgrade -y && \
apt-get install --no-install-recommends \
cmake \
gdb \
git \
googletest \
g++ \
libgtest-dev \
libncurses5-dev \
make \
neovim \
tree -y \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/*

RUN rm -rf /game-of-life
COPY . /game-of-life/
WORKDIR /game-of-life
