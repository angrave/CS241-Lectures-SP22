#include <stdio.h>

int main() {
  printf("String at address %p \n", "Me String");
  
  int bad = (int) "Hi";
  printf("Hex bad = %x\n", bad);
  puts( (char*) bad);
  return 0;
}
