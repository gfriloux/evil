#ifdef HAVE_CONFIG_H
# include "config.h"
#endif /* HAVE_CONFIG_H */

#include "Evil.h"
#include "evil_private.h"


#ifdef _WIN32_WCE

/*
 * Error related functions
 *
 */

char *strerror (int errnum EVIL_UNUSED)
{
   return "[Windows CE] error\n";
}

#endif /* _WIN32_WCE */


/*
 * bit related functions
 *
 */

int ffs(int i)
{
   int size;
   int x;

   if (!i) return 1;

   /* remove the sign bit */
   x = i & -i;
   size = sizeof(int) << 3;
   for (i = size; i > 0; --i, x <<= 1)
     if (x & (1 << (size - 1))) return i;

   return x;
}


#ifdef _WIN32_WCE

/*
 * String manipulation related functions
 *
 */

int
strcoll (const char *s1, const char *s2)
{
#ifdef UNICODE
   wchar_t *ws1;
   wchar_t *ws2;
   int      res;

   ws1 = evil_char_to_wchar(s1);
   ws2 = evil_char_to_wchar(s2);
   res = wcscmp(ws1, ws2);
   if (ws1) free(ws1);
   if (ws2) free(ws2);

   return res;
#else
   return strcmp(s1, s2);
#endif /* ! UNICODE */
}


#endif /* _WIN32_WCE */

char *
strrstr (const char *str, const char *substr)
{
  char *it,
       *ret = NULL;
   size_t l = strlen(substr);

   it = (char *)str;

  while ((it = strstr(it, substr)))
    {
       ret = it;
       it += l;
    }

  return ret;
}

#ifdef _MSC_VER

int strcasecmp(const char *s1, const char *s2)
{
   return lstrcmpi(s1, s2);
}

#endif /* _MSC_VER */

char *strcasestr(const char *haystack, const char *needle)
{
   size_t length_needle;
   size_t length_haystack;
   size_t i;

   if (!haystack || !needle)
     return NULL;

   length_needle = strlen(needle);
   length_haystack = strlen(haystack) - length_needle + 1;

   for (i = 0; i < length_haystack; i++)
     {
        size_t j;

        for (j = 0; j < length_needle; j++)
          {
            unsigned char c1;
            unsigned char c2;

            c1 = haystack[i+j];
            c2 = needle[j];
            if (toupper(c1) != toupper(c2))
              goto next;
          }
        return (char *) haystack + i;
     next:
        ;
     }

   return NULL;
}

char *strndup(const char *s, size_t n)
{
   char *p;
   size_t l = strlen (s);

   if (l > n)
     l = n;

   p = (char *) malloc (l + 1);
   if (!p)
     return NULL;

   p[l] = '\0';
   return (char *) memcpy (p, s, l);
}

void *memrchr(const void *s, int c, size_t n)
{
   const unsigned char *cp;

   if (!n)
     return NULL;

   cp = (unsigned char *)s + n;
   do {
      if (*(--cp) == (unsigned char)c)
        return (void *)cp;
   } while (--n != 0);

   return NULL;
}
