#!/usr/bin/bash

if [[ -f ./call_private_basic ]]; then
  rm ./call_private_basic
fi

clang++ -I../target/include/ -ldl -L../target/ -ltarget_basic ./src/call_private_basic.cpp -o ./call_private_basic