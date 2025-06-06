# Yet Another C++ Tetris

A simple tetris C++ pet-project

Uses SDL2 (SDL3 when?)

All instructions are for debian-like linux distributions for now, use docker or whatever if you don't have it installed (build container support coming soon).

# Prerequisites

You'll need to install SDL for now, later there'll be a docker image? Maybe?

Anyway, do
```sh
sudo apt update
sudo apt install libsdl2-dev
```

# Building and running

To configure project, run
```
./configure.sh
```

To build and run either run [build_n_launch.sh](build_n_launch.sh) or [rebuild_n_launch.sh](rebuild_n_launch.sh)

Example of first start:
```
./configure.sh
./build_n_launch.sh
```

# TODO

- Tetris functionality
- Cross-platform portability? (docker?)
- Custom tetris sprites?
