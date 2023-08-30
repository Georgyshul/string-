#include "../s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
  size_t result_length = 0;
  int allowed_byte_flag = 1;

  while (*str1 && allowed_byte_flag) {
    char *found_byte = s21_strchr(str2, *str1);

    if (found_byte) {
      result_length++;
      str1++;
    } else {
      allowed_byte_flag = 0;
    }
  }

  return result_length;
}