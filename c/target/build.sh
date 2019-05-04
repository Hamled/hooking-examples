#!/usr/bin/bash

if [[ -f ./libtarget.so ]]; then
  rm ./libtarget.so
fi

clang -shared -I./include/ ./src/target.c -o ./libtarget.so

# Don't include the local function symbol
strip -N say_something ./libtarget.so
