
void mystrcat(char* dst, const char* src) {


  while( *src ) {
    dst = src;
  
    dst++;
    src++;
  }
}

#include <stdio.h>
int main(int argc, char** argv) {

  char dest[16];
  dest[0] = 'x'; 
  dest[1] = '\0'; // 0

  char* source = "ABC";
  mystrcat(dest, source);
  printf("Result is %s\n",dest);
  return 0;
}
