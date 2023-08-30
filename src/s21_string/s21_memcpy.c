#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *pdest = (unsigned char *)dest;
  unsigned const char *psrc = (unsigned const char *)src;

  if (pdest && psrc) {
    while (n--) {
      *(pdest++) = *(psrc++);
    }
  }

  return dest;
}