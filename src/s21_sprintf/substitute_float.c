#include "s21_sprintf.h"

int substitute_float_integer(char **insert_text,
                             specifier_struct *format_specifier, va_list ap) {
  char float_string[DIGITS_IN_FLOAT] = {0};

  double num = va_arg(ap, double);

  if (num < 0) {
    num *= (-1);
    format_specifier->is_negative = 1;
  }

  decimal_float_to_ascii(num, float_string, format_specifier);

  int size_of_abs_float = s21_strlen(float_string);

  int template_width = get_width_float(size_of_abs_float, format_specifier);

  make_template_array(insert_text, template_width);

  int idx1 = apply_flags_and_precision(*insert_text, format_specifier,
                                       size_of_abs_float, template_width);

  int idx2 = size_of_abs_float - 1;

  for (; idx2 >= 0; idx1--, idx2--) {
    (*insert_text)[idx1] = float_string[idx2];
  }

  return template_width;
}