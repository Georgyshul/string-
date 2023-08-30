#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *last_occurance = NULL;

  while (*str) {
    if ((int)*str == c) last_occurance = (char *)str;
    str++;
  }

  if (*str == '\0' && c == '\0') {
    last_occurance = (char *)str;
  }

  return last_occurance;
}