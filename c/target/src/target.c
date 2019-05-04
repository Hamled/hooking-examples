#include <stdio.h>
#include <stdlib.h>
#include "target.h"

static void __attribute__((__noinline__)) say_something() {
  puts("This is really something!");
}

void maybe_say(int num) {
  if(num == rand()) {
    say_something();
  }
}
