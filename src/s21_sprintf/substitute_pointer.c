#include "s21_sprintf.h"

int substitute_pointer(char **insert_text, specifier_struct *format_specifier,
                       va_list ap) {
  char address[32] = {0};

  size_t ptr = va_arg(ap, unsigned long int);

  int_to_ascii(ptr, address, 16);

  int length = s21_strlen(address);

  int template_width = get_width_decimal(length, format_specifier);

  make_template_array(insert_text, template_width);

  int idx1 = apply_flags_and_precision(*insert_text, format_specifier, length,
                                       template_width);

  int idx2 = length - 1;

  if (ptr == 0 && format_specifier->precision == 0) {
    address[0] = '\0';
  }

  for (; idx2 >= 0; idx1--, idx2--) {
    (*insert_text)[idx1] = address[idx2];
  }

  return template_width;
}