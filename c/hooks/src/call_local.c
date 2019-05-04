#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// Offset of `say_something` function from start of `maybe_say`
// this was determined by reversing the libtarget.so binary
#define LOCAL_FUNC_OFFSET 0x30

int main(int argc, char **argv) {

  char *error = NULL;

  dlerror(); // Clear any existing errors
  void *lib_handle = dlopen("libtarget.so", RTLD_NOW);
  error = dlerror();

  if(lib_handle == NULL || error != NULL) {
    printf("Could not open shared library with dlopen(): %s\n", error);
    exit(EXIT_FAILURE);
  }

  dlerror(); // Clear any existing errors
  void *global_func_addr = dlsym(lib_handle, "maybe_say");
  error = dlerror();

  if(error != NULL) {
    printf("Could not get address of `maybe_say` function: %s\n", error);
    exit(EXIT_FAILURE);
  }

  printf("Address of `maybe_say` function: %p\n", global_func_addr);

  // Get a pointer to the local function `say_something
  void (*say_something)();

  say_something = global_func_addr + LOCAL_FUNC_OFFSET;

  say_something();

  exit(EXIT_SUCCESS);
}
