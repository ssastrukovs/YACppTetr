#!/bin/bash
set -euo pipefail

cmake --build ./build --config Debug --target all --
ctest --test-dir ./build --output-on-failure
