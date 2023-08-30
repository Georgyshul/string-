#ifndef SRC_S21_SSCANF_S21_SSCANF_H_
#define SRC_S21_SSCANF_S21_SSCANF_H_

#include <limits.h>
#include <stdarg.h>

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long double ldouble;

typedef struct {
  /* Width description */
  int width;
  int skip;

  /* Length */
  int short_int;
  int long_int;
  int long_double;

  /* Specifier */
  char specifier;

  /* Additional info*/
  int is_negative;
} specifier_struct_scanf;

int s21_sscanf(const char *str, const char *format, ...);

void read_int(const char **str, int *number);
void get_specifier_width(const char **format,
                         specifier_struct_scanf *format_specifier);
void get_specifier_length(const char **format,
                          specifier_struct_scanf *format_specifier);
void get_specifier(const char **format,
                   specifier_struct_scanf *format_specifier);

int substitute_char_sscanf(const char *str,
                           specifier_struct_scanf *format_specifier,
                           va_list *ap);
int substitute_float_sscanf(const char *str,
                            specifier_struct_scanf *format_specifier,
                            va_list *ap);
int substitute_string_sscanf(const char *str,
                             specifier_struct_scanf *format_specifier,
                             va_list *ap);
int substitute_pointer_sscanf(const char *str,
                              specifier_struct_scanf *format_specifier,
                              va_list *ap);

#define GENERIC_FUNCTION_PROTOTYPE(type) \
  int substitute_decimal_integer_##type( \
      const char *str, specifier_struct_scanf *format_specifier, va_list *ap)

GENERIC_FUNCTION_PROTOTYPE(short);
GENERIC_FUNCTION_PROTOTYPE(int);
GENERIC_FUNCTION_PROTOTYPE(long);
GENERIC_FUNCTION_PROTOTYPE(ushort);
GENERIC_FUNCTION_PROTOTYPE(uint);
GENERIC_FUNCTION_PROTOTYPE(ulong);

#define GENERIC_FUNCTION_FLOAT_PROTOTYPE(type) \
  int substitute_float_sscanf_##type(          \
      const char *str, specifier_struct_scanf *format_specifier, va_list *ap)

GENERIC_FUNCTION_FLOAT_PROTOTYPE(float);
GENERIC_FUNCTION_FLOAT_PROTOTYPE(double);
GENERIC_FUNCTION_FLOAT_PROTOTYPE(ldouble);

#endif  // SRC_S21_SSCANF_S21_SSCANF_H_