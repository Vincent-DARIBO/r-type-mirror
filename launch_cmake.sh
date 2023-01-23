#!/bin/sh

if [ ! -d "build" ]; then mkdir build; fi
rm -rf bomberman
cd build && cmake install .. && cmake --build . && cd ..
