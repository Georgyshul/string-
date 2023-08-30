#include "s21_sprintf.h"

int substitute_decimal_integer(char **insert_text,
                               specifier_struct *format_specifier, va_list ap) {
  /*
  possible flags
      -, +, ' ', 0
  */

  char decimal_string[DIGITS_IN_INT] = {0};

  long int num = va_arg(ap, long int);

  if (format_specifier->short_int) {
    num = (short int)num;
  } else if (!format_specifier->long_int) {
    num = (int)num;
  }

  if (is_negative(num)) {
    num *= (-1);
    format_specifier->is_negative = 1;
  }

  int_to_ascii(num, decimal_string, 10);

  int size_of_abs_decimal = s21_strlen(decimal_string);

  int template_width = get_width_decimal(size_of_abs_decimal, format_specifier);

  make_template_array(insert_text, template_width);

  int idx1 = apply_flags_and_precision(*insert_text, format_specifier,
                                       size_of_abs_decimal, template_width);

  int idx2 = size_of_abs_decimal - 1;

  if (num == 0 && format_specifier->precision == 0) {
    decimal_string[0] = '\0';
  }

  for (; idx2 >= 0; idx1--, idx2--) {
    (*insert_text)[idx1] = decimal_string[idx2];
  }

  return template_width;
}