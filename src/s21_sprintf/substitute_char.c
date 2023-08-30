#include "s21_sprintf.h"

int substitute_char(char **insert_text, specifier_struct *format_specifier,
                    va_list ap) {
  format_specifier->precision = 1;

  int width = max(format_specifier->width, 1);
  make_template_array(insert_text, width);

  char *dest_pointer = *insert_text;

  if (!format_specifier->flag_minus) {
    dest_pointer += width - 1;
  }

  if (format_specifier->long_int) {
    wchar_t w_char = va_arg(ap, wchar_t);

    mbstate_t ps;
    s21_memset(&ps, 0, sizeof(ps));
    wcrtomb(dest_pointer, w_char, &ps);
  } else {
    *dest_pointer = va_arg(ap, int);
  }

  return width;
}