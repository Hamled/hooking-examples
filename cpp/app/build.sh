#!/usr/bin/bash

if [[ -f ./app_basic ]]; then
  rm ./app_basic
fi

clang++ -I../target/include/ -L../target/ -ltarget_basic ./src/app_basic.cpp -o app_basic
