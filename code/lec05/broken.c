#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char**argv) {
    srand(time(NULL));
    pid_t child = fork();
    printf("My fork value is %d\n", (int) child );
    if( child ==0) { //I am the child
      sleep(5);
    }
    int r = rand() & 0xf;
    printf("%d: My random number is %d\n", getpid(), r);
    int r2 = rand() & 0xf;
    printf("%d: My random number is %d\n", getpid(), r2);
    return 0;
}
