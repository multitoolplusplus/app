@echo off

mkdir build
cd build
cmake ..
if %errorlevel% ne 0 exit /b %errorlevel%
cmake --build .
if %errorlevel% ne 0 exit /b %errorlevel%