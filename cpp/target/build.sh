#!/usr/bin/bash

if [[ -f ./libtarget_basic.so ]]; then
  rm ./libtarget_basic.so
fi

clang++ -shared -I./include/ ./src/target_basic.cpp -o ./libtarget_basic.so
