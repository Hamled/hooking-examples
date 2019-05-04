#!/usr/bin/bash

if [[ -f ./no_work ]]; then
  rm ./no_work
fi

clang -I../target/include/ -L../target/ -ltarget ./src/no_work.c -o ./no_work
