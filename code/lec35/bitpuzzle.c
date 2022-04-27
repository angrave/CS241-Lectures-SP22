#include <stdio.h>
// also try with ~16

int main() {
  int i = ~ 0;
  printf("%d  %x\n", i,i);
  int j = (1+2+4+8) & ~ 2;
  printf("%d\n",j);
  return 1;
}
