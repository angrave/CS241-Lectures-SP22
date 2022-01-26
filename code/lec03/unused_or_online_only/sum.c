// Sum an array of positive numbers, storing
// the result in `result` (by ref)
// and use asprintf to return a text version of result 

char* mysum(const int *ptr, int *result) {
  assert(ptr);
  assert(result);

  int sum =0;
  while ( *ptr ) { 
     sum += *ptr;
     ptr++;
  }
  *result = sum;

  char *text = NULL;
  asprintf( &text, "%d", sum);

  return text;
}

