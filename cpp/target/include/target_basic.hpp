#pragma once

// Basic target with private member function
// the private function does not reference `this`

class Target {
public:
  void maybe_say(int num);

private:
  void say_something();
};
