#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *start_ptr;
  char *token = NULL;

  if (str) start_ptr = str;

  if ((str || (!str && start_ptr)) && *start_ptr != '\0') {
    token = start_ptr;
    char *end_ptr = s21_strpbrk(token, delim);

    if (end_ptr != NULL) {
      while (token - end_ptr == 0) {
        ++token;

        if (*token != '\0') {
          end_ptr = s21_strpbrk(token, delim);
        } else {
          token = NULL;
        }
      }

      start_ptr = end_ptr + 1;
      *end_ptr = '\0';
    } else {
      start_ptr = NULL;
    }
  }

  return token;
}