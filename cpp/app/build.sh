#!/usr/bin/bash

if [[ -f ./app_basic ]]; then
  rm ./app_basic
fi

clang++ -I../target/include/ -L../target/ -ltarget_basic ./src/app_basic.cpp -o app_basic

if [[ -f ./app_complex ]]; then
  rm ./app_complex
fi

clang++ -I../target/include/ -L../target/ -ltarget_complex ./src/app_complex.cpp -o app_complex
