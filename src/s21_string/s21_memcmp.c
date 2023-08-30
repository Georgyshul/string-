#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int result = 0;
  size_t i = 0;

  do {
    if (*((char *)str1 + i) != *((char *)str2 + i))
      result = *((char *)str1 + i) - *((char *)str2 + i);
  } while (*((char *)str1 + i) != '\0' && *((char *)str1 + i++) != '\0' &&
           i < n && !result);

  return result;
}