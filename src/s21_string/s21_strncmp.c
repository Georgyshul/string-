#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int counter = (int)n;

  for (; (*str1 && --counter && (*str1 == *str2)); str1++, str2++)
    ;

  int result = 0;
  if (n > 0) result = *str1 - *str2;

  return result;
}