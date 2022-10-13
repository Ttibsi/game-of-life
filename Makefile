.PHONY: all
all:
	@echo "testenv: create env"
	@echo "generate: run cmake"
	@echo "create: run generated makefile"
	@echo "run: execute source build"
	@echo "test: build and execute tests"
	@echo "new-env: launch new tty environment"
	@echo "env: launch exciting tty environment"
	@echo "docker-clean: remove container"
	@echo "remote-clean: clear build directory in container"
	@echo ""

testenv:
	@echo "[Create Env]"
	open -a docker
	docker build -f Dockerfile -t env .
	docker run -td --name="my_env" env

generate:
	@echo "[Running CMake]"
	docker exec my_env cmake -DRUN_TESTS=OFF -S /game-of-life/ -B build/

create: generate
	@echo "[Running generated Makefile]"
	docker exec --workdir="/game-of-life/build/" my_env make

run: testenv create
	docker exec my_env ./build/src/gol

gdb:
	@echo "[Running GDB]"
	docker exec my_env cmake -DCMAKE_BUILD_TYPE=Debug -DRUN_TESTS=OFF -S /game-of-life/ -B build/
	docker exec --workdir="/game-of-life/build/" my_env make
	echo "enter env and run gdb"
	echo "https://stackoverflow.com/a/3719031"

test: testenv
	docker exec my_env cmake -DRUN_TESTS=ON -S /game-of-life/ -B build/
	docker exec --workdir="/game-of-life/build/tests/" my_env make
	docker exec my_env ./build/tests/test

new-env: testenv
	@echo "[Launch new TTY]"
	docker exec -ti my_env bash

env:
	@echo "[Launch existing TTY]"
	docker exec -ti my_env bash

docker-clean:
	@echo "[Removing container]"
	docker kill $$(docker ps -q)
	docker container prune -f

remote-clean:
	@echo "[Cleaning build]"
	docker exec my_env rm -rf build/
