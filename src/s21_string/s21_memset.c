#include "../s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
  size_t i = 0;
  while (i < n) {
    *((char *)str + i++) = c;
  }

  return str;
}