#!/usr/bin/bash

if [[ -f ./app ]]; then
  rm ./app
fi

clang -I../target/include -L../target/ -ltarget src/app.c -o app
