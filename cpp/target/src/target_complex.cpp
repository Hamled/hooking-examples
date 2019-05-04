#include <iostream>
#include <cstdlib>
#include "target_complex.hpp"

void __attribute__((__noinline__)) Target::say_something() {
  std::cout << this->message << std::endl;
}

void Target::maybe_say(int num) {
  if(num == std::rand()) {
    this->say_something();
  }
}

Target::Target() {
  this->message = "This is really something!";
}

Target::~Target() {
  this->message = NULL;
}
