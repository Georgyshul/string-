#include "../s21_string.h"

void *s21_memmove(void *dest, const void *src, size_t n) {
  unsigned char *pdest = (unsigned char *)dest;
  const unsigned char *psrc = (const unsigned char *)src;

  if (!pdest || !psrc) {
    dest = NULL;
  } else {
    if (psrc < pdest) {
      for (psrc += n, pdest += n; n--;) {
        *(--pdest) = *(--psrc);
      }
    } else {
      while (n--) {
        *(pdest++) = *(psrc++);
      }
    }
  }

  return dest;
}