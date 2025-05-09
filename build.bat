@echo off

mkdir build
cd build
cmake ..
cmake --build .
echo Done. The executable is in ./build/Debug directory.
