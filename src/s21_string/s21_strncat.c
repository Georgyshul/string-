#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *pointer_dest = dest;
  const char *pointer_src = src;

  for (; *(pointer_dest); pointer_dest++)
    ;

  while (n--) {
    *(pointer_dest++) = *(pointer_src++);
  }
  *(pointer_dest) = '\0';

  return dest;
}