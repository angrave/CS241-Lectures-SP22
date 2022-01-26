#include <assert.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char**argv) {
  assert(argc == 2);
  assert( strcmp(argv[1], "LA") == 0 );
  puts("Everything OK!");
  printf("%s %d\n", __FILE__, __LINE__);
  return 0;
}
