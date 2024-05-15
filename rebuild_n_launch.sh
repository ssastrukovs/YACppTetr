#!/bin/bash
cmake --build ./build --config Debug --target clean --
cmake --build ./build --config Debug --target all --
./build/YACppQtTetr