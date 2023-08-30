#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *pointer_str1 = (char *)str1;
  int found_flag = 0;

  while (*pointer_str1 && !found_flag) {
    char *found_char = s21_strchr(str2, *pointer_str1);
    if (found_char) {
      found_flag = 1;
    } else {
      pointer_str1++;
    }
  }

  if (!*pointer_str1) pointer_str1 = NULL;

  return pointer_str1;
}