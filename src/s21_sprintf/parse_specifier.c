#include "s21_sprintf.h"

void parse_specifier_flags(specifier_struct *format_specifier,
                           const char **format) {
  char flag = *(*format);

  while (flag == MINUS || flag == PLUS || flag == SPACE || flag == HASH ||
         flag == ZERO) {
    switch (flag) {
      case MINUS:
        format_specifier->flag_minus = 1;
        break;
      case PLUS:
        format_specifier->flag_plus = 1;
        break;
      case SPACE:
        format_specifier->flag_space = 1;
        break;
      case HASH:
        format_specifier->flag_hash = 1;
        break;
      case ZERO:
        format_specifier->flag_zero = 1;
    }
    flag = *(++(*format));
  }
  if (format_specifier->flag_minus && format_specifier->flag_zero) {
    format_specifier->flag_zero = 0;
  }
}

void parse_specifier_width(specifier_struct *format_specifier,
                           const char **format, va_list ap) {
  if (*(*format) == '*') {
    format_specifier->width = va_arg(ap, int);
    (*format)++;
  } else {
    /*
    *******************Warning*******************
    In this implementation '0' can be first digit
    */
    char digit_string[DIGITS_IN_INT] = {0};
    char *pointer_digit = (char *)digit_string;

    while (s21_strchr("0123456789", *(*format))) {
      *(pointer_digit++) = *((*format)++);
    }

    format_specifier->width = atoi(digit_string);
  }
}

void parse_specifier_precision(specifier_struct *format_specifier,
                               const char **format, va_list ap) {
  if (*(*format) == '.') {
    (*format)++;
    if (*(*format) == '*') {
      format_specifier->precision = va_arg(ap, int);
      (*format)++;
    } else {
      char digit_string[DIGITS_IN_INT] = {0};
      char *pointer_digit = (char *)digit_string;

      while (s21_strchr("0123456789", *(*format))) {
        *(pointer_digit++) = *((*format)++);
      }

      format_specifier->precision = atoi(digit_string);
    }
  }
}

void parse_specifier_length(specifier_struct *format_specifier,
                            const char **format) {
  switch (*(*format)) {
    case 'h':
      format_specifier->short_int = 1;
      (*format)++;
      break;
    case 'l':
      format_specifier->long_int = 1;
      (*format)++;
      break;
    case 'L':
      // format_specifier->long_double = 1;
      (*format)++;
      break;
    default:
      break;
  }
}