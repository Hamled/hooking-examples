#include <iostream>
#include <cstdlib>

// Copied from target_complex.hpp (no need to directly reference header)
class Target {
public:
  void maybe_say(int num);
  Target();
  ~Target();
  void say_something(); // Move target function to public scoping

private:
//  void say_something();
  const char *message;
};

int main(int argc, char **argv) {
  // Construct an instance of Target class
  Target t = Target();

  // Call private function
  t.say_something();

  return EXIT_SUCCESS;
}
