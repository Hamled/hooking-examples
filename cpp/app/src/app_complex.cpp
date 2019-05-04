#include <iostream>
#include <cstdlib>
#include "target_complex.hpp"

int main(int argc, char **argv) {
  if(argc < 2) {
    std::cout << "Usage: " << argv[0] << " <integer>" << std::endl;
    return EXIT_FAILURE;
  }

  int input = std::atoi(argv[1]);
  Target t = Target();
  t.maybe_say(input);

  return EXIT_SUCCESS;
}
