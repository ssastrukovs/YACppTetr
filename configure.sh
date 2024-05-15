#!/bin/bash
if [ ! -d "build" ]; then
    echo "Build directory doesn't exist. Configuring..."
    mkdir -p ../build
    cmake --no-warn-unused-cli -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_C_COMPILER:FILEPATH=gcc -DCMAKE_CXX_COMPILER:FILEPATH=g++ -S. -B./build -G Ninja
fi