#include <iostream>
#include <cstdlib>
#include <dlfcn.h>

// Copied from target_complex.hpp (no need to directly reference header)
class Target {
public:
  void maybe_say(int num);
  Target();
  ~Target();

private:
  void say_something();
  const char *message;
};

// Determined with objdump -d libtarget_complex.so
// because for some reason readelf was truncating symbol names
const char *PRIVATE_FUNC_NAME = "_ZN6Target13say_somethingEv";

int main(int argc, char **argv) {
  char *error = NULL;

  dlerror(); // Clear any existing errors
  void *lib_handle = dlopen("libtarget_complex.so", RTLD_NOW);
  error = dlerror();

  if(lib_handle == NULL || error != NULL) {
    std::cout << "Could not open shared library with dlopen(): " << (error || "Unknown") << std::endl;
    return EXIT_FAILURE;
  }

  dlerror(); // Clear any existing errors
  void *private_func_addr = dlsym(lib_handle, PRIVATE_FUNC_NAME);
  error = dlerror();

  if(error != NULL) {
    std::cout << "Could not get address of `Target::say_something` function: " << error << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Address of `Target::say_something` function: " << private_func_addr << std::endl;

  // Get a pointer to the private function `Target::say_something`
  void (*say_something)();
  say_something = (void (*)())private_func_addr;

  // Construct an instance of Target class
  Target t = Target();

  // Put it on the stack per cdecl calling convention
  // If this were thiscall, you'd need to mov it into [R|E]AX
  asm("push %0" : : "rm"(&t));

  // Call private function
  say_something();

  return EXIT_SUCCESS;
}
