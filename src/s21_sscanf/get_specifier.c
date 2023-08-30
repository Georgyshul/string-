#include "s21_sscanf.h"

void read_int(const char **str, int *number);

void get_specifier_width(const char **format,
                         specifier_struct_scanf *format_specifier) {
  if (**format == '*') {
    format_specifier->skip = 1;
    ++(*format);
  } else {
    read_int(format, &(format_specifier->width));
    if (format_specifier->width == 0) {
      format_specifier->width = INT_MAX;
    }
  }
}

void get_specifier_length(const char **format,
                          specifier_struct_scanf *format_specifier) {
  switch (**format) {
    case 'h':
      format_specifier->short_int = 1;
      ++(*format);
      break;
    case 'l':
      format_specifier->long_int = 1;
      ++(*format);
      break;
    case 'L':
      format_specifier->long_double = 1;
      ++(*format);
      break;
  }
}

void get_specifier(const char **format,
                   specifier_struct_scanf *format_specifier) {
  format_specifier->specifier = **format;
  ++(*format);
}

// HAHAHAH

void read_int(const char **str, int *number) {
  *number = 0;
  while (**str >= '0' && **str <= '9') {
    *number *= 10;
    *number += (**str - '0');
    ++(*str);
  }
}