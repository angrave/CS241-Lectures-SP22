#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
void quit(char*mesg) { perror(mesg); exit(1); }

int main(int argc, char**argv) {
    sigset_t mask;
    sigset_t orig_mask;
    sigemptyset (&mask);
    sigaddset (&mask, SIGTERM);
    puts("SIG_BLOCKing SIGTERM"); 
    if (sigprocmask(SIG_BLOCK, &mask, &orig_mask) < 0) quit("sigprocmask");
    
    puts("raising SIGTERM");
    raise( SIGTERM);

    sigset_t pending;
    if( sigpending( &pending) <0) quit("sigpending");

    printf("SIGTERM sigismember:%d\n", sigismember(&pending, SIGTERM));
    
    puts("Now exec-ing prog2...");
    execlp("./prog2","./prog2",(char*)NULL);
    quit("exec");
    return 1;
}
