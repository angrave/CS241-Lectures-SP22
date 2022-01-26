
char* mystrdup(const char* src) {
  
  char* result = malloc(strlen(src) + 1); // exta byte for NUL '\0' character byte
  
  strcpy(result, src);
  
  return result;
}
