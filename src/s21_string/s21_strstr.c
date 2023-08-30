#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *start_of_substring = NULL;

  for (; *haystack && !start_of_substring &&
         s21_strlen(haystack) >= s21_strlen(needle);
       haystack++) {
    char *pointer_substring = (char *)haystack;
    char *pointer_needle = (char *)needle;

    for (; *pointer_needle && (*pointer_substring == *pointer_needle);
         pointer_substring++, pointer_needle++)
      ;

    if (!(*pointer_needle)) {
      start_of_substring = (char *)haystack;
    }
  }
  return start_of_substring;
}