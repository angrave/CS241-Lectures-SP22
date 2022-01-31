#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char * m = "World";
int main() {
 	pid_t f = fork();
 	  
	if(f == -1) { perror("fork failed!"); exit(1); }

 	if( ____ ) {   /* child process */ m = "Hello"; }

 	else { // I'm the parent
 		printf("Waiting for %ld to finish\n", (long)f);

    ?
 	  }
 	  puts(m);
 	  return 42;
 	}
