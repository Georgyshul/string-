#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);

  char *begin = str;
  int error = 0;

  while (*format && !error) {
    if (*format == '%') {
      format++;

      specifier_struct format_specifier = {0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0};

      parse_specifier_flags(&format_specifier, &format);
      parse_specifier_width(&format_specifier, &format, ap);
      parse_specifier_precision(&format_specifier, &format, ap);
      parse_specifier_length(&format_specifier, &format);
      format_specifier.specifier = (*format++);

      if (!s21_strchr("cdieEfgGosuxXp%%", format_specifier.specifier)) {
        error = 1;
      } else {
        char *insert_text;
        int offset = substitute_specifier(&insert_text, &format_specifier, ap);
        s21_strcpy(str, insert_text);
        str += offset;
        free(insert_text);
      }

    } else {
      *(str++) = *(format++);
    }
  }

  va_end(ap);

  return s21_strlen(begin);
}

int substitute_specifier(char **insert_text, specifier_struct *format_specifier,
                         va_list ap) {
  int offset;

  if (format_specifier->precision == -1) {
    set_default_precision(format_specifier);
  }

  if (format_specifier->specifier == 'c') {
    offset = substitute_char(insert_text, format_specifier, ap);
  } else if (format_specifier->specifier == 'd' ||
             format_specifier->specifier == 'i') {
    offset = substitute_decimal_integer(insert_text, format_specifier, ap);
  } else if (format_specifier->specifier == 'f') {
    offset = substitute_float_integer(insert_text, format_specifier, ap);
  } else if (format_specifier->specifier == 's') {
    offset = substitute_string(insert_text, format_specifier, ap);
  } else if (format_specifier->specifier == 'u') {
    offset = substitute_unsigned_integer(insert_text, format_specifier, ap, 10);
  } else if (format_specifier->specifier == '%') {
    *insert_text = (char *)calloc(2, sizeof(char));
    **insert_text = '%';
    offset = 1;
  } else if (format_specifier->specifier == 'o') {
    offset = substitute_unsigned_integer(insert_text, format_specifier, ap, 8);
  } else if (format_specifier->specifier == 'x' ||
             format_specifier->specifier == 'X') {
    offset = substitute_unsigned_integer(insert_text, format_specifier, ap, 16);
  } else if (format_specifier->specifier == 'p') {
    offset = substitute_pointer(insert_text, format_specifier, ap);
  } else if (format_specifier->specifier == 'e' ||
             format_specifier->specifier == 'E') {
    offset = substitute_scientific(insert_text, format_specifier, ap);
  }

  return offset;
}