#include "s21_sprintf.h"

int substitute_string(char **insert_text, specifier_struct *format_specifier,
                      va_list ap) {
  char *string = va_arg(ap, char *);

  int precision = format_specifier->precision;
  int length_string = s21_strlen(string);

  if (precision != -1) {
    length_string = min(precision, length_string);
  }

  int template_width = max(length_string, format_specifier->width);

  make_template_array(insert_text, template_width);

  int idx = format_specifier->flag_minus ? 0 : template_width - length_string;

  for (int i = 0; i < length_string; i++) {
    (*insert_text)[i + idx] = string[i];
  }

  return template_width;
}
