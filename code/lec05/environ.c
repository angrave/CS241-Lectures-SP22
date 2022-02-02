#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    puts( getenv("HOME"));

    puts( getenv("PATH");

    puts( getenv("USER") ;

    puts( getenv("AWESOME");

    // To iterator through all environment variables use environ ...
    extern char** environ; // The extern is important! 
    // -Storage for this variable is already defined outside this compilation unit

    return 0;
}
