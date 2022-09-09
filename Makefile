testenv:
	@echo "[Create Env]"
	open -a docker
	docker build -f Dockerfile -t env .
	docker run -td --name="my_env" env 

generate:
	@echo "[Running CMake]"
	docker exec my_env cmake -S /game-of-life/ -B build/

create: generate
	@echo "[Running generated Makefile]"
	docker exec --workdir="/game-of-life/build/" my_env make 

run: create
	docker exec my_env ./build/src/gol

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
	docker run --rm env rm -rf build/*