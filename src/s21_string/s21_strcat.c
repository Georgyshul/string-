#include "../s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *pointer_dest = dest;
  const char *pointer_src = src;

  for (; *(pointer_dest); pointer_dest++)
    ;

  while (*pointer_src) {
    *(pointer_dest++) = *(pointer_src++);
  }
  *pointer_dest = '\0';

  return dest;
}