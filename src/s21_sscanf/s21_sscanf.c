#include "s21_sscanf.h"

enum { ok = 1, wrong = 0 };

void skip_all_spaces(const char **str, const char **format);
int substitute_specifier_scanf(const char *str,
                               specifier_struct_scanf *format_specifier,
                               va_list *vl);
void init(specifier_struct_scanf *format_specifier);

int s21_sscanf(const char *str, const char *format, ...) {
  va_list vl;
  va_start(vl, format);
  int format_check = ok;

  const char *begin = str;
  int readed_fields_counter = 0;

  while (*format && format_check) {
    skip_all_spaces(&str, &format);

    if (*format == '%' && *(format + 1) == 'n') {
      int *n = va_arg(vl, int *);
      *n = str - begin;
    }

    if (*format == '%' && *(format + 1) != '%') {
      ++format;
      if (*format != 'c') {
        while (*str == ' ' || *str == '\n') ++str;
      }

      specifier_struct_scanf format_specifier;
      init(&format_specifier);
      get_specifier_width(&format, &format_specifier);
      get_specifier_length(&format, &format_specifier);
      get_specifier(&format, &format_specifier);

      if (format_specifier.specifier != 'n') {
        int offset = substitute_specifier_scanf(str, &format_specifier, &vl);
        str += offset;
        if (!format_specifier.skip && offset != 0) ++readed_fields_counter;
      }

    } else {
      if (*format == '%') {
        if (*str == '%') {
          format += 2;
          ++str;
        } else {
          format_check = wrong;
        }
      } else if (*format == *str) {
        ++format;
        ++str;
      } else if (*format == ' ' || *format == '\n') {
        ++format;
      } else if (*str == ' ' || *str == '\n') {
        ++str;
      } else {
        format_check = wrong;
      }
    }
  }

  va_end(vl);

  if (*begin == '\0') readed_fields_counter = -1;
  return readed_fields_counter;
}

void skip_all_spaces(const char **str, const char **format) {
  if ((**str == ' ' && **format == ' ') ||
      (**str == '\n' && **format == '\n') ||
      (**str == ' ' && **format == '\n') ||
      (**str == '\n' && **format == ' ')) {
    while (**str == ' ' || **str == '\n') ++(*str);
    while (**format == ' ' || **str == '\n') ++(*format);
  }
}

int substitute_specifier_scanf(const char *str,
                               specifier_struct_scanf *format_specifier,
                               va_list *vl) {
  int offset = 0;
  if (*str != '\0') {
    if (format_specifier->specifier == 'c') {
      offset = substitute_char_sscanf(str, format_specifier, vl);
    } else if (format_specifier->specifier == 'd' ||
               format_specifier->specifier == 'i') {
      if (format_specifier->short_int) {
        offset = substitute_decimal_integer_short(str, format_specifier, vl);
      } else if (format_specifier->long_int) {
        offset = substitute_decimal_integer_long(str, format_specifier, vl);
      } else {
        offset = substitute_decimal_integer_int(str, format_specifier, vl);
      }
    } else if (format_specifier->specifier == 'o' ||
               format_specifier->specifier == 'u' ||
               format_specifier->specifier == 'x' ||
               format_specifier->specifier == 'X') {
      if (format_specifier->short_int) {
        offset = substitute_decimal_integer_ushort(str, format_specifier, vl);
      } else if (format_specifier->long_int) {
        offset = substitute_decimal_integer_ulong(str, format_specifier, vl);
      } else {
        offset = substitute_decimal_integer_uint(str, format_specifier, vl);
      }
    } else if (format_specifier->specifier == 'f' ||
               format_specifier->specifier == 'e' ||
               format_specifier->specifier == 'E' ||
               format_specifier->specifier == 'g' ||
               format_specifier->specifier == 'G') {
      if (format_specifier->long_double) {
        offset = substitute_float_sscanf_ldouble(str, format_specifier, vl);
      } else if (format_specifier->long_int) {
        offset = substitute_float_sscanf_double(str, format_specifier, vl);
      } else {
        offset = substitute_float_sscanf_float(str, format_specifier, vl);
      }
    } else if (format_specifier->specifier == 's') {
      offset = substitute_string_sscanf(str, format_specifier, vl);
    } else if (format_specifier->specifier == 'p') {
      offset = substitute_pointer_sscanf(str, format_specifier, vl);
    }
  }

  return offset;
}

void init(specifier_struct_scanf *format_specifier) {
  format_specifier->is_negative = 0;
  format_specifier->long_double = 0;
  format_specifier->long_int = 0;
  format_specifier->short_int = 0;
  format_specifier->skip = 0;
  format_specifier->specifier = 'd';
  format_specifier->width = INT_MAX;
}