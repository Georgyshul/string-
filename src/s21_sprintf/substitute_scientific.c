#include "s21_sprintf.h"

int substitute_scientific(char **insert_text,
                          specifier_struct *format_specifier, va_list ap) {
  long double val = 0;

  if (format_specifier->long_double) {
    val = va_arg(ap, long double);
  } else {
    val = va_arg(ap, double);
  }

  if (val < 0) {
    val *= (-1);
    format_specifier->is_negative = 1;
  }

  char sign = '+';
  int power = get_power_for_scientific(&val, &sign);

  char float_string[DIGITS_IN_FLOAT] = {0};
  decimal_float_to_ascii(val, float_string, format_specifier);

  char power_string[DIGITS_IN_INT] = {0};
  int_to_ascii(power, power_string, 10);

  int length_scientific =
      get_length_scientific(float_string, power_string, format_specifier);

  int template_width = max(length_scientific, format_specifier->width);

  make_template_array(insert_text, template_width);

  int length_abs_scientific = length_scientific;
  if (format_specifier->flag_plus || format_specifier->flag_space ||
      format_specifier->is_negative) {
    length_abs_scientific -= 1;
  }

  int idx = apply_flags_and_precision(*insert_text, format_specifier,
                                      length_abs_scientific, template_width);

  int length_float = s21_strlen(float_string);
  int length_power = s21_strlen(power_string);

  for (int i = length_power - 1; i >= 0; i--, idx--) {
    (*insert_text)[idx] = power_string[i];
  }

  if (length_power == 1) {
    (*insert_text)[idx--] = '0';
  }

  (*insert_text)[idx--] = sign;

  switch (format_specifier->specifier) {
    case 'e':
      (*insert_text)[idx--] = 'e';
      break;
    case 'E':
      (*insert_text)[idx--] = 'E';
      break;
  }

  for (int i = length_float - 1; i >= 0; i--, idx--) {
    (*insert_text)[idx] = float_string[i];
  }

  return template_width;
}