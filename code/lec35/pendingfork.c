#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>

int main(int argc, char**argv) {
    sigset_t mask;
    sigset_t orig_mask;
    sigemptyset (&mask);
    sigaddset (&mask, SIGINT);
    puts("SIGBLOCK-ing SIGINT"); 
    sigprocmask(SIG_BLOCK, &mask, &orig_mask);
    
    puts("Raising SIGINT");
    raise(SIGINT);
    
    puts("forking...");
    pid_t pid = fork();

    printf("pid: %d resetting process mask\n", (int) getpid() );
    sigprocmask(SIG_SETMASK, &orig_mask, NULL);

    if(pid==0) 
      printf("I'm the child (%d) and I'm still alive! - will exit normally\n",(int)getpid());
    else 
      printf("I'm the parent (%d) and I'm still alive! - will exit normally!\n", (int)getpid());

    return 1;
}
