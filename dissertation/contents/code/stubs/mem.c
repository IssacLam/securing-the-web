inline void *memcpy(void *dst, const void *src, size_t n)
{
	/* detailed implementation is omitted */
//	for(__CPROVER_size_t i=0; i<n ; i++)
//        ((char *)dst)[i]=((const char *)src)[i];

    __CPROVER_assert(n > 0, "memcpy n is least or equal to zero");
    ((char *)dst)[n-1];
    ((const char *)src)[n-1];
  	return dst;
}

inline void *memset(void *s, int c, size_t n)
{
    /* detailed implementation is omitted */
    //  char *sp=s;
    //  for(__CPROVER_size_t i=0; i<n ; i++) sp[i]=c;
    
    __CPROVER_assert(n > 0, "memset n is least or equal to zero");
    ((char *)s)[n-1];
    return s;
}

inline int memcmp(const void *s1, const void *s2, size_t n)
{
    /* detailed implementation is omitted */
    _Bool res;
    //  int res=0;
    //  const unsigned char *sc1=s1, *sc2=s2;
    //  for(; n!=0; n--)
    //  {
    //    res = (*sc1++) - (*sc2++);
    //    if (res != 0)
    //      return res;
    //  }
    
     __CPROVER_assert(n > 0, "memcmp n is least or equal to zero");
    ((const char *)s1)[n-1];
    ((const char *)s2)[n-1];
    return (res)? 0 : 1;
}