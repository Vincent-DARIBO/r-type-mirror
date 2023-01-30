#!/bin/sh

if [ ! -d "build" ]; then mkdir build; fi
rm -rf r-type
cd build && cmake install .. && cmake --build .