#include "s21_sprintf.h"

void set_default_precision(specifier_struct *format_specifier) {
  switch (format_specifier->specifier) {
    case 'd':
      format_specifier->precision = 1;
      break;

    case 'i':
      format_specifier->precision = 1;
      break;

    case 'f':
      format_specifier->precision = 6;
      break;
    case 'e':
      format_specifier->precision = 6;
      break;
    case 'E':
      format_specifier->precision = 6;
      break;
    case 'g':
      format_specifier->precision = 6;
      break;
    case 'G':
      format_specifier->precision = 6;
      break;
    default:
      break;
  }
}

void int_to_ascii(long int num, char *decimal_string, int radix) {
  char reversed[DIGITS_IN_INT] = {0};
  int idx = DIGITS_IN_INT - 2;

  int negative = is_negative(num);
  num = negative ? -num : num;

  if (num == 0) {
    reversed[idx] = '0';
  }

  while (num > 0) {
    idx--;
    reversed[idx] = "0123456789abcdef"[num % radix];
    num /= radix;
  }

  for (int j = 0; reversed[idx]; idx++, j++) {
    if (negative && j == 0) {
      decimal_string[j++] = '-';
    }

    decimal_string[j] = reversed[idx];
  }
}

void decimal_float_to_ascii(double num, char *float_string,
                            specifier_struct *format_specifier) {
  // fprintf(stdout, "number in decimal_float_to_ascii: %f\n", num);
  int precision = format_specifier->precision;

  long int integer_part = (long int)num;
  double fractional_part = num - integer_part;

  // fprintf(stdout, "integer part in decimal_float_to_ascii: %ld\n",
  // integer_part); fprintf(stdout, "fractional part in decimal_float_to_ascii:
  // %f\n", fractional_part);

  char integer_part_string[DIGITS_IN_INT] = {0};

  if (precision != 0) {
    int_to_ascii(integer_part, integer_part_string, 10);

    s21_strcpy(float_string, integer_part_string);

    s21_strcat(float_string, ".");
  } else {
    if ((int)(fractional_part * 10) > 4) {
      integer_part++;
    }

    int_to_ascii(integer_part, integer_part_string, 10);

    s21_strcpy(float_string, integer_part_string);
  }

  // fprintf(stdout, "integer part string in decimal_float_to_ascii: %s\n",
  // integer_part_string);

  int counter = 0;

  clarify_fractional_part_for_precisied_output(&fractional_part, precision);

  while (precision--) {
    fractional_part *= 10;
    // fprintf(stdout, "float part: %f\n", fractional_part);
    int digit = (int)(fractional_part);
    fractional_part -= digit;

    // fprintf(stdout, "float part digit %d: %d\n", counter, digit);

    // fprintf(stdout, "rest float part: %f\n", fractional_part);

    char format[] = "01234567890";

    if (precision == 0 && fractional_part * 10 > 5) {
      digit++;
    }
    s21_strncat(float_string, format + digit, 1);
    counter++;
  }
}

void clarify_fractional_part_for_precisied_output(double *fractional_part,
                                                  int precision) {
  double float_part = *fractional_part;
  long int last_digit = 0;
  double eps = 1;
  for (int i = 0; i < precision + 1; i++) {
    eps = eps / 10;
    float_part *= 10;
    last_digit = (int)float_part;
    float_part -= last_digit;
  }

  if (last_digit > 4) {
    *fractional_part += eps * (10 - last_digit);
  }
}

int is_negative(long int num) { return num < 0 ? 1 : 0; }

int max(int num1, int num2) { return num1 > num2 ? num1 : num2; }

int min(int num1, int num2) { return num1 > num2 ? num2 : num1; }

int get_width_decimal(int size_of_abs_decimal,
                      specifier_struct *format_specifier) {
  int decimal_size = size_of_abs_decimal;
  int precision = format_specifier->precision;

  if ((format_specifier->is_negative || format_specifier->flag_space ||
       format_specifier->flag_plus) &&
      format_specifier->specifier != 'u' &&
      format_specifier->specifier != 'o' &&
      format_specifier->specifier != 'x' &&
      format_specifier->specifier != 'X') {
    decimal_size++;
    precision++;
  }

  if (format_specifier->specifier == 'p') {
    decimal_size += 2;
    precision += 2;
  }

  if (format_specifier->flag_hash) {
    switch (format_specifier->specifier) {
      case 'x':
        decimal_size += 2;
        precision += 2;
        break;
      case 'X':
        decimal_size += 2;
        precision += 2;
        break;
      case 'o':
        decimal_size++;
        precision++;
        break;
      default:
        break;
    }
  }

  int template_size = max(decimal_size, precision);
  template_size = max(template_size, format_specifier->width);

  return template_size;
}

int get_width_float(int size_of_abs_float, specifier_struct *format_specifier) {
  int size_of_float = size_of_abs_float;
  int width = format_specifier->width;

  if (format_specifier->is_negative || format_specifier->flag_space ||
      format_specifier->flag_plus) {
    size_of_float++;
  }

  return max(size_of_float, width);
}

int get_length_scientific(char *float_string, char *power_string,
                          specifier_struct *format_specifier) {
  int length_float = s21_strlen(float_string);
  int length_power = s21_strlen(power_string);

  if (length_power == 1) {
    length_power++;
  }

  int length_total = length_float + length_power + 1 + 1;

  if (format_specifier->flag_plus || format_specifier->flag_space ||
      format_specifier->is_negative) {
    length_total++;
  }

  return length_total;
}

void make_template_array(char **template, int width) {
  *template = (char *)calloc(width + 1, sizeof(char));

  s21_memset(*template, ' ', width);
}

int apply_flags_and_precision(char *template,
                              specifier_struct *format_specifier,
                              int size_of_abs_decimal, int template_width) {
  char specifier = format_specifier->specifier;

  if (format_specifier->flag_zero) {
    for (int i = 0; i < template_width; i++) {
      template[i] = '0';
    }
  }

  int length_of_precised_decimal;

  switch (specifier) {
    case 'd':
      length_of_precised_decimal =
          max(size_of_abs_decimal, format_specifier->precision);
      break;
    case 'i':
      length_of_precised_decimal =
          max(size_of_abs_decimal, format_specifier->precision);
      break;
    case 'u':
      length_of_precised_decimal =
          max(size_of_abs_decimal, format_specifier->precision);
      break;
    case 'o':
      length_of_precised_decimal =
          max(size_of_abs_decimal, format_specifier->precision);
      break;
    case 'f':
      length_of_precised_decimal = size_of_abs_decimal;
      break;
    case 'x':
      length_of_precised_decimal =
          max(size_of_abs_decimal, format_specifier->precision);
      break;
    case 'X':
      length_of_precised_decimal =
          max(size_of_abs_decimal, format_specifier->precision);
      break;
    case 'p':
      length_of_precised_decimal =
          max(size_of_abs_decimal, format_specifier->precision);
      break;
    case 'e':
      length_of_precised_decimal = size_of_abs_decimal;
      break;
    case 'E':
      length_of_precised_decimal = size_of_abs_decimal;
      break;
  }

  int idx = 0;

  if ((format_specifier->is_negative || format_specifier->flag_space ||
       format_specifier->flag_plus) &&
      !(specifier == 'u' || specifier == 'o' || specifier == 'x' ||
        specifier == 'X')) {
    idx = 1;
  } else if (format_specifier->flag_hash &&
             (specifier == 'x' || specifier == 'X')) {
    idx = 2;
  } else if (format_specifier->flag_hash && specifier == 'o') {
    idx = 1;
  }

  if (specifier == 'p') {
    idx += 2;
  }

  if (!format_specifier->flag_minus) {
    idx = template_width - length_of_precised_decimal;
  }

  if (format_specifier->specifier != 'u' &&
      format_specifier->specifier != 'o' &&
      format_specifier->specifier != 'x' &&
      format_specifier->specifier != 'X') {
    if (format_specifier->is_negative) {
      if (format_specifier->flag_zero) {
        template[0] = '-';
      } else if (specifier == 'p') {
        template[idx - 3] = '-';
      } else {
        template[idx - 1] = '-';
      }
    } else if (format_specifier->flag_space) {
      if (format_specifier->flag_zero) {
        template[0] = ' ';
      } else if (specifier == 'p') {
        template[idx - 3] = ' ';
      } else {
        template[idx - 1] = ' ';
      }
    } else if (format_specifier->flag_plus) {
      if (format_specifier->flag_zero) {
        template[0] = '+';
      } else if (specifier == 'p') {
        template[idx - 3] = '+';
      } else {
        template[idx - 1] = '+';
      }
    }
  }

  if (format_specifier->flag_hash || specifier == 'p') {
    if (specifier == 'o') {
      template[idx - 1] = '0';
    } else if (specifier == 'x' || specifier == 'p') {
      if (format_specifier->flag_zero) {
        template[0] = '0';
        template[1] = 'x';
      } else {
        template[idx - 2] = '0';
        template[idx - 1] = 'x';
      }
    } else if (specifier == 'X') {
      if (format_specifier->flag_zero) {
        template[0] = '0';
        template[1] = 'X';
      } else {
        template[idx - 2] = '0';
        template[idx - 1] = 'X';
      }
    }
  }

  if (specifier == 'd' || specifier == 'i' || specifier == 'u' ||
      specifier == 'o' || specifier == 'x' || specifier == 'X' ||
      specifier == 'p' || specifier == 'e' || specifier == 'E') {
    for (int i = idx; i < idx + length_of_precised_decimal; i++) {
      template[i] = '0';
    }
  }

  return idx + length_of_precised_decimal - 1;
}

void change_case(char *decimal_string) {
  char *literals = "abcdef";
  while (*decimal_string) {
    if (s21_strchr(literals, *decimal_string)) {
      *decimal_string = *decimal_string - 32;
    }
    decimal_string++;
  }
}

int get_power_for_scientific(long double *val, char *sign) {
  int power = 0;

  if (*val != 0.0) {
    if (*val < 1) {
      *sign = '-';
    } else {
      *sign = '+';
    }

    while (*val < 1) {
      *val *= 10;
      power++;
    }

    while (*val >= 10) {
      *val /= 10;
      power++;
    }
  }

  return power;
}

// void print_struct(specifier_struct *format_specifier) {
//   printf("\n----specifier_struct----\n");
//   printf("flag_minus: %d\n", format_specifier->flag_minus);
//   printf("flag_plus: %d\n", format_specifier->flag_plus);
//   printf("flag_space: %d\n", format_specifier->flag_space);
//   printf("flag_hash: %d\n", format_specifier->flag_hash);
//   printf("flag_zero: %d\n", format_specifier->flag_zero);

//   printf("\nwidth: %d\n", format_specifier->width);

//   printf("\nprecision: %d\n", format_specifier->precision);

//   printf("\nnegative_flag: %d\n", format_specifier->is_negative);
// }