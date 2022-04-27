#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// exec this program after setting the process mask

void quit(char*mesg) {perror(mesg); exit(1);}

void handler(int sig) {
    char*mesg = "prog2:(handler) SIGTERM CAUGHT!\n";
    write(1,mesg, strlen(mesg));
}

int main() {
//    signal( SIGTERM, handler);

    puts("prog2: starting up");
    sigset_t pending;
    if( sigpending( &pending) <0) quit("prog2: sigpending");

    printf("prog2:SIGTERM sigismember:%d\n", sigismember(&pending, SIGTERM));

    sleep(2);
    sigset_t mask;
    sigemptyset(&mask);

    puts("prog2:Changing process mask to the empty set");
    sigprocmask(SIG_SETMASK, &mask, NULL);

    puts("prog2:Shields are down");
    return 0;
}
