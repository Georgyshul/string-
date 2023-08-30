#ifndef SRC_S21_SPRINTF_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_S21_SPRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

#include "../s21_string.h"

// #define INT_MAX 2147483647
#define DIGITS_IN_INT 16
#define DIGITS_IN_FLOAT 60  // ???
#define MAX_LEN_SUB 512
#define PRECISION_DEF 6

#define MINUS '-'
#define PLUS '+'
#define SPACE ' '
#define HASH '#'
#define ZERO '0'

/*
struct SpecifierStruct - the structure to describe a format specifier

prototype of format string: %[flags][width][.precision][length]specifier

Flag characters
    -      Left-justify within the given field width; Right justification is the
default.

    +      A sign (+ or -) should always be placed before a number produced by a
signed conversion. By default, a sign is used only for negative numbers.

    ' '    A blank should be left before a positive number (or empty string)
produced by a signed conversion.

    #      The value should be converted to an "alternate form" (read manual).

    0      Left-pads the number with zeroes (0) instead of spaces, where padding
is specified.

Field width
    An optional decimal digit string (with nonzero first digit) specifying a
minimum field width. If the converted value has fewer characters than the field
width, it will be padded with spaces on the left (or right, if the
left-adjustment flag has been given).

Precision

Length modifier
    h   The argument is interpreted as a short int or unsigned short int
        (only applies to integer specifiers: i, d, o, u, x and X).

    l   long int or unsigned long int for integer specifiers (i, d, o, u, x and
X), and as a wide character or wide character string for specifiers c and s.

    L   The argument is interpreted as a long double (only applies to
        floating point specifiers − e, E, f, g and G).

Specifier
*/

typedef struct {
  /* Flags */
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_hash;
  int flag_zero;

  /* Width value */
  int width;

  /* Precision */
  int precision;

  /* Length */
  int short_int;
  int long_int;
  int long_double;

  /* Specifier */
  char specifier;

  /* Additional info*/
  int is_negative;
} specifier_struct;

int s21_sprintf(char *str, const char *format, ...);

// specifier parser
void parse_specifier_flags(specifier_struct *format_specifier,
                           const char **format);

void parse_specifier_width(specifier_struct *format_specifier,
                           const char **format, va_list ap);

void parse_specifier_precision(specifier_struct *format_specifier,
                               const char **format, va_list ap);

void parse_specifier_length(specifier_struct *format_specifier,
                            const char **format);

// substitute string instead of specifier
int substitute_specifier(char **insert_text, specifier_struct *format_specifier,
                         va_list ap);

int substitute_char(char **insert_text, specifier_struct *format_specifier,
                    va_list ap);

int substitute_decimal_integer(char **insert_text,
                               specifier_struct *format_specifier, va_list ap);

int substitute_unsigned_integer(char **insert_text,
                                specifier_struct *format_specifier, va_list ap,
                                int base);

int substitute_float_integer(char **insert_text,
                             specifier_struct *format_specifier, va_list ap);

int substitute_string(char **insert_text, specifier_struct *format_specifier,
                      va_list ap);

int substitute_pointer(char **insert_text, specifier_struct *format_specifier,
                       va_list ap);

int substitute_scientific(char **insert_text,
                          specifier_struct *format_specifier, va_list ap);

// helpers
void set_default_precision(specifier_struct *format_specifier);

void int_to_ascii(long int num, char *decimal_string, int radix);

void decimal_float_to_ascii(double num, char *float_string,
                            specifier_struct *format_specifier);

int is_negative(long int num);

int max(int num1, int num2);

int min(int num1, int num2);

int get_width_decimal(int size_of_abs_decimal,
                      specifier_struct *format_specifier);

int get_width_float(int size_of_abs_float, specifier_struct *format_specifier);

int get_length_scientific(char *float_string, char *power_string,
                          specifier_struct *format_specifier);

void make_template_array(char **template, int width);

int apply_flags_and_precision(char *template,
                              specifier_struct *format_specifier,
                              int size_of_abs_decimal, int template_width);

void clarify_fractional_part_for_precisied_output(double *fractional_part,
                                                  int precision);

void change_case(char *decimal_string);

int get_power_for_scientific(long double *val, char *sign);

void print_struct(specifier_struct *format_specifier);

#endif  // RC_S21_SPRINTF_S21_SPRINTF_H_