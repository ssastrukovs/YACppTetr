#!/bin/bash
cmake --build ./build --config Debug --target all --
./build/YACppQtTetr
rm -f ./compile_commands.json
ln -s ./build/compile_commands.json ./compile_commands.json
