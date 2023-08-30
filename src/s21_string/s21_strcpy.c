#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *pointer_dest = dest;
  const char *pointer_src = src;

  do {
    *(pointer_dest++) = *pointer_src;
  } while (*(pointer_src++));

  return dest;
}