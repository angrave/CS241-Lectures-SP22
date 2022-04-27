
#include <stdio.h>
#include <unistd.h>

// gcc takeovertheworld.c -o takeovertheworld

int main(int argc, char** argv) {

  
  int busy = 7;
  if(argv[1]) sscanf(argv[1], "%d", &busy);
  
  puts("Taking over the world");
  sleep(1);
  puts("Acquiring Vulnerable Network of Internet of Things");
  sleep(1);  

  puts("Installing distributed-AI (version 5)");
  fflush(stdout);

  for(;busy; busy--) { 
    printf("\r --- Please wait %d seconds --- ", busy);
    fflush(stdout); 
    sleep(1);
   }
  puts("\033[2J Installation complete. Have a nice day.");
  return 42;
}
