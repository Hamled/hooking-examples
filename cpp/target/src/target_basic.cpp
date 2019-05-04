#include <iostream>
#include <cstdlib>
#include "target_basic.hpp"

void __attribute__((__noinline__)) Target::say_something() {
  std::cout << "This is really something!" << std::endl;
}

void Target::maybe_say(int num) {
  if(num == std::rand()) {
    this->say_something();
  }
}
