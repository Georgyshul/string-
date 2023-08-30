#include "../s21_string.h"

char *s21_strerror(int errnum) {
  static char return_message[MAX_LEN];

  if (errnum < 0 || errnum > MAX_ERROR_CODE || ERROR_LIST[errnum] == NULL) {
    s21_sprintf(return_message, "Unknown error %d", errnum);
  } else {
    s21_strncpy(return_message, ERROR_LIST[errnum], MAX_LEN);
  }

  return return_message;
}