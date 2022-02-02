#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
   close(1); // closes filedescriptor associated with standard out
   // open will use smallest unused non-negative filedescriptor ... Guess which one!
   open("log.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
   
   puts("Captain's log"); // Clibrary detects output written to a file

   chdir("/bin");
   fflush(stdout);
   
   execl("/bin/ls", "/bin/ls",".",(char*)NULL); // "ls ."
   perror("exec failed");
   return 0; // Not expected to get here
}
