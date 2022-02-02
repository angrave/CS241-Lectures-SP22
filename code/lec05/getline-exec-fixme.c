#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {
  char* line = NULL;
  size_t size =0;
  printf("What is thy command? > ");
  
  ssize_t bytesread = getline(&line, &size, stdin); 
   line[bytesread-1] = '\0';

  printf("We are about to run : '%s'", line);
  fflush(stdout);
  
  execlp(line, line, (char*)NULL);
  perror("execlp failed!");
  
  return 0; 
}
