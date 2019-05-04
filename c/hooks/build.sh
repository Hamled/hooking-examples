#!/usr/bin/bash

if [[ -f ./no_work ]]; then
  rm ./no_work
fi

clang -I../target/include/ -L../target/ -ltarget ./src/no_work.c -o ./no_work

if [[ -f ./call_local ]]; then
  rm ./call_local
fi

clang -I../target/include/ -ldl -L../target/ -ltarget ./src/call_local.c -o ./call_local
