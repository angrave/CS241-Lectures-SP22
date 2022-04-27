#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
 int main() {
  sleep(4);
  sigset_t pending;
  sigpending( &pending);

   int ctrl_c = sigismember(&pending, SIGINT);
   if(ctrl_c) {
     puts("Mwa Mwa Mwa");
   }
  return 0;
}

