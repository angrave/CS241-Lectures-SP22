#include <unistd.h>
#include <stdio.h>

int main(int argc, char**argv) {
   printf("Executing %s ...", *(argv+ 1) );   // arg[1]
   fflush(stdout); // ensure libc calls write(...)
   execvp( argv [1], argv + 1); // NULL TERMINATED
   perror("Failed to be all powerful");
   return 1;
}
