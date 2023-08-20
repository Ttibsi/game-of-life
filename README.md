# game-of-life
This repo is intended to be `Conway's Game of Life`, which I'm developing
predominantly for learning and practice purposes.

The goals of this project are to get used to working with c++ in a project that
is of a reasonable size, to learn how to use `CMake` and `Docker`, and write
unit tests using `googletest` in c++

## To Run
Make sure docker is installed on your system from your package manager or from
https://www.docker.com/ as this all builds within a container.

`make testenv run` will create the environment, build the binary, and execute the
game. For concecutive runs after the first, make sure you run `make docker-clean`
first.

You can adjust the game by changing the numbers in src/config.json. A
pre-configured file is already present.

```json
{
    "size": "Length of the board size",
    "iter": "How many iterations of the board to display",
    "coords": "A list of coordinate pairs to populate the board with. Neither value should be higher than the size value"
}
```
