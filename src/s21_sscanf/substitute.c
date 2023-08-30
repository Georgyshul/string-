#include "s21_sscanf.h"

#define GENERIC_FUNCTION(type)                                          \
  int substitute_decimal_integer_##type(                                \
      const char *str, specifier_struct_scanf *format_specifier,        \
      va_list *ap) {                                                    \
    type number = 0;                                                    \
    int index = 0;                                                      \
    int multiplier = 10;                                                \
    int is_hexadecimal = 0;                                             \
                                                                        \
    if (str[index] == '-') {                                            \
      format_specifier->is_negative = 1;                                \
      ++index;                                                          \
    }                                                                   \
                                                                        \
    calculate_decimal_type(&index, &multiplier, str, format_specifier); \
    if (multiplier == 16) is_hexadecimal = 1;                           \
                                                                        \
    number = 0;                                                         \
    for (; is_number(str[index], is_hexadecimal) &&                     \
           (index < format_specifier->width);                           \
         ++index) {                                                     \
      number *= multiplier;                                             \
      number += ascii_to_number(str[index]);                            \
    }                                                                   \
                                                                        \
    if (!format_specifier->skip) {                                      \
      type *number_out = va_arg(*ap, type *);                           \
      *number_out = number;                                             \
      if (format_specifier->is_negative) {                              \
        *number_out *= -1;                                              \
      }                                                                 \
    }                                                                   \
                                                                        \
    return index;                                                       \
  }

void calculate_decimal_type(int *index, int *multiplier, const char *str,
                            specifier_struct_scanf *format_specifier);
int is_number(char c, int is_hexadecimal);
int ascii_to_number(char c);

GENERIC_FUNCTION(short)
GENERIC_FUNCTION(int)
GENERIC_FUNCTION(long)
GENERIC_FUNCTION(ushort)
GENERIC_FUNCTION(uint)
GENERIC_FUNCTION(ulong)

int substitute_char_sscanf(const char *str,
                           specifier_struct_scanf *format_specifier,
                           va_list *ap) {
  if (!format_specifier->skip) {
    char *c = va_arg(*ap, char *);
    *c = *str;
  }

  return 1;
}

#define GENERIC_FUNCTION_FLOAT(type)                                           \
  int substitute_float_sscanf_##type(const char *str,                          \
                                     specifier_struct_scanf *format_specifier, \
                                     va_list *ap) {                            \
    int index = 0;                                                             \
    type integer = 0;                                                          \
    type fractional = 0;                                                       \
    int fractional_mult = 0;                                                   \
                                                                               \
    int exponent = 0;                                                          \
    type multiplier = 10;                                                      \
                                                                               \
    if (str[index] == '-') {                                                   \
      format_specifier->is_negative = 1;                                       \
      ++index;                                                                 \
    }                                                                          \
                                                                               \
    for (; is_number(str[index], 0) && (index < format_specifier->width);      \
         ++index) {                                                            \
      integer *= 10;                                                           \
      integer += ascii_to_number(str[index]);                                  \
    }                                                                          \
                                                                               \
    if (str[index] == '.' && (index < format_specifier->width)) {              \
      ++index;                                                                 \
                                                                               \
      while (str[index] == '0') {                                              \
        ++fractional_mult;                                                     \
        ++index;                                                               \
      }                                                                        \
      for (; is_number(str[index], 0) && (index < format_specifier->width);    \
           ++index) {                                                          \
        fractional *= 10;                                                      \
        fractional += ascii_to_number(str[index]);                             \
      }                                                                        \
      while (fractional >= 1) {                                                \
        fractional /= 10;                                                      \
      }                                                                        \
      for (; fractional_mult > 0; --fractional_mult) {                         \
        fractional *= 0.1;                                                     \
      }                                                                        \
    }                                                                          \
                                                                               \
    if (str[index] == 'e' && (index < format_specifier->width)) {              \
      ++index;                                                                 \
                                                                               \
      if (str[index] == '-' && (index < format_specifier->width)) {            \
        ++index;                                                               \
        multiplier = 0.1;                                                      \
      }                                                                        \
                                                                               \
      for (; is_number(str[index], 0) && (index < format_specifier->width);    \
           ++index) {                                                          \
        exponent *= 10;                                                        \
        exponent += ascii_to_number(str[index]);                               \
      }                                                                        \
    }                                                                          \
                                                                               \
    if (!format_specifier->skip) {                                             \
      type *float_out = va_arg(*ap, type *);                                   \
      *float_out = integer + fractional;                                       \
      for (; exponent > 0; --exponent) {                                       \
        *float_out *= multiplier;                                              \
      }                                                                        \
                                                                               \
      if (format_specifier->is_negative) {                                     \
        *float_out *= -1;                                                      \
      }                                                                        \
    }                                                                          \
                                                                               \
    return index;                                                              \
  }

GENERIC_FUNCTION_FLOAT(float);
GENERIC_FUNCTION_FLOAT(double);
GENERIC_FUNCTION_FLOAT(ldouble);

int substitute_string_sscanf(const char *str,
                             specifier_struct_scanf *format_specifier,
                             va_list *ap) {
  int index = 0;

  if (!format_specifier->skip) {
    char *string_out = va_arg(*ap, char *);

    for (; index < format_specifier->width && str[index] != '\0' &&
           str[index] != ' ';
         ++index) {
      if (!format_specifier->skip) string_out[index] = str[index];
    }

    if (!format_specifier->skip) string_out[index] = '\0';
  } else {
    for (; index < format_specifier->width && str[index] != '\0' &&
           str[index] != ' ';
         ++index)
      ;
  }

  return index;
}

int substitute_pointer_sscanf(const char *str,
                              specifier_struct_scanf *format_specifier,
                              va_list *ap) {
  int index = 0;
  long int number = 0;

  if (str[index] == '-') {
    format_specifier->is_negative = 1;
    ++index;
  }

  if (str[index] == '0') {
    ++index;
    if (str[index] == 'x' || str[index] == 'X') {
      ++index;
    }
  }

  for (; is_number(str[index], 1) && (index < format_specifier->width);
       ++index) {
    number *= 16;
    number += ascii_to_number(str[index]);
  }

  if (format_specifier->is_negative) {
    number *= -1;
  }

  if (!format_specifier->skip) {
    void **pointer_out = va_arg(*ap, void **);
    *pointer_out = (void *)number;
  }

  return index;
}

void calculate_decimal_type(int *index, int *multiplier, const char *str,
                            specifier_struct_scanf *format_specifier) {
  if (format_specifier->specifier == 'i') {
    if (str[*index] == '0') {
      ++*index;
      if (str[*index] == 'x' || str[*index] == 'X') {
        ++*index;
        *multiplier = 16;
      } else {
        *multiplier = 8;
      }
    }
  } else if (format_specifier->specifier == 'o') {
    *multiplier = 8;
  } else if (format_specifier->specifier == 'x' ||
             format_specifier->specifier == 'X') {
    if (str[*index] == '0') {
      ++*index;
      if (str[*index] == 'x' || str[*index] == 'X') {
        ++*index;
      }
    }
    *multiplier = 16;
  }
}

int is_number(char c, int is_hexadecimal) {
  int is_number = 0;
  if (is_hexadecimal) {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
        (c >= 'a' && c <= 'f')) {
      is_number = 1;
    }
  } else {
    if (c >= '0' && c <= '9') {
      is_number = 1;
    }
  }

  return is_number;
}

int ascii_to_number(char c) {
  int number = 0;
  if (c >= '0' && c <= '9') {
    number = c - '0';
  } else if (c >= 'A' && c <= 'F') {
    number = c - 'A' + 10;
  } else if (c >= 'a' && c <= 'f') {
    number = c - 'a' + 10;
  }

  return number;
}