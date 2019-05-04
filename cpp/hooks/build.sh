#!/usr/bin/bash

if [[ -f ./call_private_basic ]]; then
  rm ./call_private_basic
fi

clang++ -I../target/include/ -ldl -L../target/ -ltarget_basic ./src/call_private_basic.cpp -o ./call_private_basic

if [[ -f ./call_private_complex ]]; then
  rm ./call_private_complex
fi

clang++ -I../target/include/ -ldl -L../target/ -ltarget_complex ./src/call_private_complex.cpp -o ./call_private_complex

if [[ -f ./call_private_nodlsym ]]; then
  rm ./call_private_nodlsym
fi

clang++ -I../target/include/ -ldl -L../target/ -ltarget_complex ./src/call_private_nodlsym.cpp -o ./call_private_nodlsym
