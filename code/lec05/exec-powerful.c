#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if( argc <2 ) {
    fprintf(stderr,"Usage: %s program-to-run [arg1] [arg2]\n", argv[0] );
    exit(1);
  }
  char* prog_name = argv[1];

  execvp( prog_name, argv + 1 );
  perror("Exec failed!");
  exit(1);
}

