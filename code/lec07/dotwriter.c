#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void dontdothat(int signal) {
  char* m ="Stop that!\n";
  write(1, m , strlen(m) );
}

void alarmed(int signal) {
  write(1, "ARGH!", 4);
}
int main() {
  alarm(4);
  signal(SIGALRM, alarmed );
  signal(SIGINT, dontdothat );
  printf("My pid is %d\n", getpid() );
  int i = 60;
  while(--i) { 
    write(1, ".",1);
    sleep(1);
    if(i == 55) kill( getpid() , SIGINT );
  }
  write(1, "Done!",5);
  return 0;
}
