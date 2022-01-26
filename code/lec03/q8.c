
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv) {
  char* ptr = NULL; 
  // Use address-of my variable ...
  asprintf( & ptr , "%s/%s %d" , "123","456",78);

  printf("ptr is now %p and at that location: %s\n", ptr, ptr);
  free( ptr );
  ptr = NULL;
  
  return 0;
}
