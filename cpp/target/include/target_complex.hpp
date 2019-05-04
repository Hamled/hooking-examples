#pragma once

// Complex target with private member function
// which *does* reference `this` to access private
// member initialized by constructor.

class Target {
public:
  void maybe_say(int num);
  Target();
  ~Target();

private:
  void say_something();
  const char *message;
};
