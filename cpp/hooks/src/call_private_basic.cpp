#include <iostream>
#include <cstdlib>
#include <dlfcn.h>

// Offset of `Target::say_something` function from start of `maybe_say`
// this was determined by reversing the libtarget.so binary
//const int LOCAL_FUNC_OFFSET = 0x30;

// Determined with readelf -s libtarget_basic.so
const char *PRIVATE_FUNC_NAME = "_ZN6Target13say_somethingEv";

int main(int argc, char **argv) {
  char *error = NULL;

  dlerror(); // Clear any existing errors
  void *lib_handle = dlopen("libtarget_basic.so", RTLD_NOW);
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

  // Get a pointer to the local function `say_something
  void (*say_something)();

  say_something = (void (*)())private_func_addr;

  say_something();

  return EXIT_SUCCESS;
}
