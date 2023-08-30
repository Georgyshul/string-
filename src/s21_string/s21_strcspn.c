#include "../s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t result_length = 0;
  int forbidden_byte_flag = 0;

  while (*str1 && !forbidden_byte_flag) {
    char *found_byte = s21_strchr(str2, *str1);

    if (found_byte) {
      forbidden_byte_flag = 1;
    } else {
      str1++;
      result_length++;
    }
  }

  return result_length;
}