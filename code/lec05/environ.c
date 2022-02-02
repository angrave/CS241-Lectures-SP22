#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char** environ;

int main() {

    puts( getenv("HOME"));

    puts( getenv("PATH"));

    puts( getenv("USER")) ;

    //puts( getenv("AWESOME") );

    // To iterator through all environment variables use environ ...
     // The extern is important! 
    // -Storage for this variable is already defined outside this compilation unit
    char** p = environ;
    while(*p) {
      puts(*p);
      p++;
    }
    return 0;
}
