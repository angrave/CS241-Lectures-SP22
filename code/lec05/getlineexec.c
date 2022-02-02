#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
   char* line = NULL;
   size_t size = 0;
   printf("What is thou command oh cs241 person?\n> ");

   size = getline( & line, &size, stdin);
if(size>0)
      line[size -1] = '\0';
   printf("About to run %s", line);
   fflush(stdout);
   
   execlp(line,  line, (char*) NULL);
   fprintf(stderr,"failed to exec %s\n",line);
   return 0;
}
