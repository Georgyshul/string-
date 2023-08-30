#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  char *point = NULL;
  size_t i = 0;
  if (n != 0) {
    do {
      if (*((char *)str + i) == c) point = (char *)str + i;
    } while (*((char *)str + i++) != '\0' && i < n && !point);
  }

  return point;
}