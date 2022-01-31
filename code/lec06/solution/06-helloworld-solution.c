#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char * m = "World";
int main() {
 	pid_t f = fork();
 	  
	if(f == -1) { perror("fork failed!"); exit(1); }

 	if(f == 0) {   /* child process */ m = "Hello"; }

 	else { // I'm the parent
 		printf("Waiting for %ld to finish\n", (long)f);

    int status;
    waitpid( f, & status, 0);
		  printf(" raw value of status is %d\n", status);
		  if(WIFEXITED(status) ) {
  		 	printf("Child returned %d\n", WEXITSTATUS(status));
      }
		else puts("Child did not exit normally\n");
  
 	}
 	puts(m);

  * "Read only"  = 123;
  
  exit(42);
  return 42;
}
