#include "s21_sprintf.h"

int substitute_unsigned_integer(char **insert_text,
                                specifier_struct *format_specifier, va_list ap,
                                int base) {
  char unsigned_string[DIGITS_IN_INT] = {0};

  unsigned long int num = va_arg(ap, unsigned long int);

  if (format_specifier->short_int) {
    num = (unsigned short int)num;
  } else if (!format_specifier->long_int) {
    num = (unsigned int)num;
  }

  int_to_ascii(num, unsigned_string, base);

  if (format_specifier->specifier == 'X') {
    change_case(unsigned_string);
  }

  int size_of_unsigned = s21_strlen(unsigned_string);

  int template_width = get_width_decimal(size_of_unsigned, format_specifier);

  make_template_array(insert_text, template_width);

  int idx1 = apply_flags_and_precision(*insert_text, format_specifier,
                                       size_of_unsigned, template_width);

  int idx2 = size_of_unsigned - 1;

  if (num == 0 && format_specifier->precision == 0) {
    unsigned_string[0] = '\0';
  }

  for (; idx2 >= 0; idx1--, idx2--) {
    (*insert_text)[idx1] = unsigned_string[idx2];
  }

  return template_width;
}