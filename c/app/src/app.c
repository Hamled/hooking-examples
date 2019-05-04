#include <stdio.h>
#include <stdlib.h>
#include "target.h"

int main(int argc, char **argv) {
  if(argc < 2) {
    printf("Usage: %s <integer>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int input = atoi(argv[1]);
  maybe_say(input);

  exit(EXIT_SUCCESS);
}
