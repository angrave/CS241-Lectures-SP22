#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static sigset_t   signal_mask;  
int problems = 9;

void *signal_thread (void *arg);

int main (int argc, char *argv[])
{
    pthread_t  thr_id;      /* signal handler thread ID */
    sigemptyset (&signal_mask);
    sigaddset (&signal_mask, SIGINT);
    sigaddset (&signal_mask, SIGQUIT);
    pthread_sigmask (SIG_BLOCK, &signal_mask, NULL);

    pthread_create(&thr_id, NULL, signal_thread, NULL);
    while(problems) {
      problems --;
      putchar('.'); fflush(stdout);
      sleep(1);
    }
    return 0;
}

void *signal_thread (void *arg)
{
    int       sig;   

    while(1) {
        puts("signal thread is waiting...");
        sigwait (&signal_mask, &sig);
        switch (sig)
        {
        case SIGINT:     /* process SIGINT  */
            printf("\nThere are %d problems left to solve\n", problems);
        break;
        case SIGQUIT:    /* process SIGQUIT */
            printf("\nDon't SIGQUIT me!\n");
        break;
        default:         
            printf("Unexpected signal %d\n", sig);
        break;
        }
    }
}

