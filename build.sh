#!/bin/sh

set -e

mkdir -p build
cd build
cmake ..
cmake --build .
echo "Done. The executable is in ./build directory."
