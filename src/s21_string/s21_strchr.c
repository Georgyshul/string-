#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *first_occurence = (char *)str;

  for (; (*first_occurence) && (*first_occurence != c); first_occurence++)
    ;

  if ((c != '\0') && (!*first_occurence)) first_occurence = NULL;

  return first_occurence;
}