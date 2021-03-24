
// HelloWorld includes
#include <HelloWorld.h>

// STD includes
#include <cstdlib>

extern "C" {
  extern void F_helloworld_display(void);
}

int main(int, char*[])
{
  F_helloworld_display();
  return EXIT_SUCCESS;
}
