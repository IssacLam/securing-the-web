inline size_t strlen(const char *s)
{
  /* detailed implementation is omitted */
  __CPROVER_size_t len=0;
  while(s[len]!=0) len++;
  return len;
}