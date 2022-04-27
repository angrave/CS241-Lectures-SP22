#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void func(int signal) {
  write(1,"HELLO\n",6);
}

int main() {
   // change the signal disposition
   signal( SIGINT, func );

   pid_t pid = fork();

   if(pid==0)
      printf("I'm the child (%d) and I'm still alive! - will exit normally\n",(int)getpid());
    else
      printf("I'm the parent (%d) and I'm still alive! - will exit normally!\n", (int)getpid());

   sleep(100);
   return 0;
}

