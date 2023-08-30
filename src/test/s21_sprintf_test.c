#include "test.h"

// Char
START_TEST(sprintf_char_flags) {
  char str1[512] = {0};
  char str2[512] = {0};

  char ch = 'f';

  char *format = "'-': %-10c\n'+': %+c\n' ': % c\n'#': %#c\n'0': %020c";

  ck_assert_int_eq(s21_sprintf(str1, format, ch, ch, ch, ch, ch),
                   sprintf(str2, format, ch, ch, ch, ch, ch));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_0) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "hello %c %c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a', 'b'),
                   sprintf(str2, format, 'a', 'b'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_1) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "hello %-7c %-c %1c %2c %+3c % c %*c %c";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 10, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'),
      sprintf(str2, format, 10, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_2) {
  char str1[512] = {0};
  char str2[512] = {0};

  wchar_t ch1 = 'a';
  wchar_t ch2 = 'g';

  s21_sprintf(str1, "%10lc %-10lc %lc", ch1, ch2, ch1);
  sprintf(str2, "%10lc %-10lc %lc", ch1, ch2, ch1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Int
START_TEST(sprintf_int_flags) {
  char str1[512] = {0};
  char str2[512] = {0};

  int num = 15;

  char *format =
      "'-': %-10d\n'+': %+d\n' ': % d\n'#': %#d\n'0': %020d\n '-' and '0': "
      "%-0d";

  ck_assert_int_eq(s21_sprintf(str1, format, num, num, num, num, num, num),
                   sprintf(str2, format, num, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_0) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "hello %d %i";

  int num1 = 0;
  int num2 = 321;

  ck_assert_int_eq(s21_sprintf(str1, format, num1, num2),
                   sprintf(str2, format, num1, num2));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_1) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "hello %-10d % d %+d %012d";

  int num1 = 123;
  int num2 = 321;

  ck_assert_int_eq(s21_sprintf(str1, format, num1, num2, num1, num2),
                   sprintf(str2, format, num1, num2, num1, num2));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_2) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "%+2.8hd, %-11.8ld, %+-10.50d, % -8d";

  ck_assert_int_eq(
      s21_sprintf(str1, format, (short int)-1234, (long int)184000000, -1234,
                  123),
      sprintf(str2, format, (short int)-1234, (long int)184000000, -1234, 123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_3) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "%-5c, %+10.5d, %-1.1d, %.0d";

  ck_assert_int_eq(s21_sprintf(str1, format, 'c', -12345, 100, 0),
                   sprintf(str2, format, 'c', -12345, 100, 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_4) {
  char str1[128];
  char str2[128];

  char *format = "This is a simple value %d";
  int val = 69;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_5) {
  char str1[128];
  char str2[128];

  char *format = "%.5i";
  int val = 69;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_6) {
  char str1[128];
  char str2[128];

  char *format = "%5d";
  int val = 69;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_7) {
  char str1[128];
  char str2[128];

  char *format = "%-5i";
  int val = 69;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_8) {
  char str1[128];
  char str2[128];

  char *format = "%012i";
  int val = 69;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_9) {
  char str1[128];
  char str2[128];

  char *format = "% d";
  int val = 0;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Float
START_TEST(sprintf_float_flags) {
  char str1[512] = {0};
  char str2[512] = {0};

  float num = +15.3;

  char *format =
      "'-': %-10f\n'+': %+f\n' ': % f\n'#': %#f\n'0': %020f\n '-' and '0': "
      "%-0f";

  ck_assert_int_eq(s21_sprintf(str1, format, num, num, num, num, num, num),
                   sprintf(str2, format, num, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_0) {
  char str1[512];
  char str2[512];

  char *format = "%f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.4560),
                   sprintf(str2, format, 123.4560));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_1) {
  char str1[512];
  char str2[512];

  char *format = "% f %f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.4, -123.4),
                   sprintf(str2, format, 123.4, -123.4));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_2) {
  char str1[512];
  char str2[512];

  char *format = "%+f %+f";
  float num = 123.4;

  ck_assert_int_eq(sprintf(str2, format, num, -num),
                   s21_sprintf(str1, format, num, -num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_3) {
  char str1[512];
  char str2[512];

  char *format = "%0f %020f";
  float num = 123.4;

  ck_assert_int_eq(s21_sprintf(str1, format, num, -num),
                   sprintf(str2, format, num, -num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_4) {
  char str1[512];
  char str2[512];

  char *format = "%-20f";
  float num = -123.902;

  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_5) {
  char str1[512];
  char str2[512];

  char *format = "%10.0f %1.0f %f";

  ck_assert_int_eq(s21_sprintf(str1, format, -123.902, 123.5, 1.123456),
                   sprintf(str2, format, -123.902, 123.5, 1.123456));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_6) {
  char str1[512];
  char str2[512];

  char *format = "%f";
  double val = 513515.131513515151351;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_7) {
  char str1[512];
  char str2[512];

  char *format = "%.0f";
  double val = 15.35;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_8) {
  char str1[512];
  char str2[512];

  char *format = "%.f";
  double val = 15.35;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_9) {
  char str1[512];
  char str2[512];

  char *format = "%.15f";
  double val = 15.35;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_10) {
  char str1[512];
  char str2[512];

  char *format = "%.15f";
  double val = -15.35581134;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_11) {
  char str1[512];
  char str2[512];

  char *format = "%f";
  double val = 72537572375.143134;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_12) {
  char str1[512];
  char str2[512];

  char *format = "% f";
  float val = 0;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// String
START_TEST(sprintf_string_flags) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *str = "hello";

  char *format =
      "'-': %-10s\n'+': %+s\n' ': % s\n'#': %#s\n'0': %020s\n '-' and '0': "
      "%-0s";

  ck_assert_int_eq(s21_sprintf(str1, format, str, str, str, str, str, str),
                   sprintf(str2, format, str, str, str, str, str, str));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_0) {
  char str1[512];
  char str2[512];

  s21_sprintf(str1, "%s", "hello");
  sprintf(str2, "%s", "hello");

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_1) {
  char str1[512] = {0};
  char str2[512] = {0};

  s21_sprintf(str1, "hello %-20s %20s %sasdfgh", "hello", "everyone", " ");
  sprintf(str2, "hello %-20s %20s %sasdfgh", "hello", "everyone", " ");

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_2) {
  char str1[512] = {0};
  char str2[512] = {0};

  s21_sprintf(str1, "hello %20.10s %-20.2s %sasdfgh", "hello", "everyone", " ");
  sprintf(str2, "hello %20.10s %-20.2s %sasdfgh", "hello", "everyone", " ");

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[512];
  char str2[512];

  char *format = "%s";
  char *val = "Lorem ipsum dolor sit amet, consectetur efficitur.";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width) {
  char str1[512];
  char str2[512];

  char *format = "%15s";
  char *val = "Lorem ipsum dolor sit id";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[512];
  char str2[512];

  char *format = "%s";
  char *val = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. ";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// Percent
START_TEST(sprintf_percent_0) {
  char str1[512] = {0};
  char str2[512] = {0};

  int num1 = s21_sprintf(str1, "hello%%hel");
  int num2 = sprintf(str2, "hello%%hel");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

// Uint
START_TEST(sprintf_uint_flags) {
  char str1[512] = {0};
  char str2[512] = {0};

  unsigned int num = 15;

  char *format =
      "'-': %-10u\n'+': %+u\n' ': % u\n'#': %#u\n'0': %020u\n '-' and '0': "
      "%-0u";

  ck_assert_int_eq(s21_sprintf(str1, format, num, num, num, num, num, num),
                   sprintf(str2, format, num, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_uint_0) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "hello %u %u";

  ck_assert_int_eq(s21_sprintf(str1, format, 0, 321),
                   sprintf(str2, format, 0, 321));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_uint_1) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "hello %-10u %u %u %012u";

  ck_assert_int_eq(s21_sprintf(str1, format, 123, 321, 321, 123),
                   sprintf(str2, format, 123, 321, 321, 123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_uint_2) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "%2.8u, %-11.8u, %-10.5u, %-8u";

  ck_assert_int_eq(s21_sprintf(str1, format, 1234, 184, 1234, 123),
                   sprintf(str2, format, 1234, 184, 1234, 123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_uint_3) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "%-5c, %10.5u, %-1.1u";

  ck_assert_int_eq(s21_sprintf(str1, format, 'c', 12345, 100),
                   sprintf(str2, format, 'c', 12345, 100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[512];
  char str2[512];

  char *format = "%u";
  unsigned int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[512];
  char str2[512];

  char *format = "%15u";
  unsigned int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[512];
  char str2[512];

  char *format = "%-16u";
  unsigned int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[512];
  char str2[512];

  char *format = "%.51u";
  unsigned int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many_flags) {
  char str1[512];
  char str2[512];

  char *format = "% 5.51u";
  unsigned int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_short) {
  char str1[512];
  char str2[512];

  char *format = "%hu";
  unsigned short int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[512];
  char str2[512];

  char *format = "%lu";
  unsigned long int val = 949149114140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Octal
START_TEST(sprintf_octal_flags) {
  char str1[512] = {0};
  char str2[512] = {0};

  int num = 15;

  char *format =
      "\n'-': %-10o\n'+': %+o\n' ': % o\n'#': %#o\n'0': %020o\n '-' and '0': "
      "%-0o";

  s21_sprintf(str1, format, num, num, num, num, num, num);
  sprintf(str2, format, num, num, num, num, num, num);
  // ck_assert_int_eq(s21_sprintf(str1, format, num, num, num, num, num, num),
  //                  sprintf(str2, format, num, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_0) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "%o";
  int val = 3210;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_1) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "hello %o";
  int val = 99987;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_2) {
  char str1[512];
  char str2[512];

  char *format = "%15o";
  int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_3) {
  char str1[512];
  char str2[512];

  char *format = "%-16o";
  int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_4) {
  char str1[512];
  char str2[512];

  char *format = "%.51o";
  int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_5) {
  char str1[512];
  char str2[512];

  char *format = "%-5.51o";
  int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_6) {
  char str1[512];
  char str2[512];

  char *format = "%o";

  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_7) {
  char str1[512];
  char str2[512];

  char *format = "%.0o";

  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_8) {
  char str1[512];
  char str2[512];

  char *format = "%hd";
  short int val = 14140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_9) {
  char str1[512];
  char str2[512];

  char *format = "%lo";
  long int val = 949149114140;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_10) {
  char str1[512];
  char str2[512];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// Hex
START_TEST(sprintf_hex_flags_1) {
  char str1[512] = {0};
  char str2[512] = {0};

  int num = 153;

  char *format =
      "\n'-': %-10x\n'+': %+x\n' ': % x\n'#': %#x\n'0': %020x\n '-' and '0': "
      "%-0x";

  ck_assert_int_eq(s21_sprintf(str1, format, num, num, num, num, num, num),
                   sprintf(str2, format, num, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_flags_2) {
  char str1[512] = {0};
  char str2[512] = {0};

  int num = 153;

  char *format =
      "\n'-': %-10X\n'+': %+X\n' ': % X\n'#': %#X\n'0': %020X\n '-' and '0': "
      "%-0X";

  ck_assert_int_eq(s21_sprintf(str1, format, num, num, num, num, num, num),
                   sprintf(str2, format, num, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width) {
  char str1[512];
  char str2[512];

  char *format = "%5x %5X";
  unsigned val = 858158158;

  ck_assert_int_eq(s21_sprintf(str1, format, val, val),
                   sprintf(str2, format, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_precision) {
  char str1[512];
  char str2[512];

  char *format = "%.15x %.15X";
  unsigned val = 858158158;

  ck_assert_int_eq(s21_sprintf(str1, format, val, val),
                   sprintf(str2, format, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_zero) {
  char str1[512];
  char str2[512];

  char *format = "%#x %#X";
  unsigned val = 213;

  ck_assert_int_eq(s21_sprintf(str1, format, val, val),
                   sprintf(str2, format, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Ptr
START_TEST(sprintf_ptr_0) {
  char str1[512];
  char str2[512];

  char *format = "%-10p % p %+p";

  ck_assert_int_eq(s21_sprintf(str1, format, format, format, format),
                   sprintf(str2, format, format, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_1) {
  char str1[512];
  char str2[512];

  char *format = "%20.15p";

  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Sci
START_TEST(sprintf_sci_flags_1) {
  char str1[512] = {0};
  char str2[512] = {0};

  double num = 0.0;

  char *format =
      "\n'-': %-10e\n'+': %+e\n' ': % e\n'#': %#e\n'0': %020e\n '-' and '0': "
      "%-0e";

  ck_assert_int_eq(s21_sprintf(str1, format, num, num, num, num, num, num),
                   sprintf(str2, format, num, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_sci_flags_2) {
  char str1[512] = {0};
  char str2[512] = {0};

  double num = 15.8;

  char *format =
      "\n'-': %-10E\n'+': %+E\n' ': % E\n'#': %#E\n'0': %020E\n '-' and '0': "
      "%-0E";

  ck_assert_int_eq(s21_sprintf(str1, format, num, num, num, num, num, num),
                   sprintf(str2, format, num, num, num, num, num, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_sci_0) {
  char str1[512] = {0};
  char str2[512] = {0};

  double num = 0.0;

  char *format = "%15e";

  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_sci_1) {
  char str1[512] = {0};
  char str2[512] = {0};

  double num = -0.00234;

  char *format = "%0.8e";

  ck_assert_int_eq(s21_sprintf(str1, format, num), sprintf(str2, format, num));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_test(void) {
  Suite *s1 = suite_create("s21_sprintf tests");

  TCase *sprintf_char = tcase_create("Sprintf_char");
  suite_add_tcase(s1, sprintf_char);
  tcase_add_test(sprintf_char, sprintf_char_flags);
  tcase_add_test(sprintf_char, sprintf_char_0);
  tcase_add_test(sprintf_char, sprintf_char_1);
  tcase_add_test(sprintf_char, sprintf_char_2);

  TCase *sprintf_int = tcase_create("Sprintf_int");
  suite_add_tcase(s1, sprintf_int);
  tcase_add_test(sprintf_char, sprintf_int_flags);
  tcase_add_test(sprintf_int, sprintf_int_0);
  tcase_add_test(sprintf_int, sprintf_int_1);
  tcase_add_test(sprintf_int, sprintf_int_2);
  tcase_add_test(sprintf_int, sprintf_int_3);
  tcase_add_test(sprintf_int, sprintf_int_4);
  tcase_add_test(sprintf_int, sprintf_int_5);
  tcase_add_test(sprintf_int, sprintf_int_6);
  tcase_add_test(sprintf_int, sprintf_int_7);
  tcase_add_test(sprintf_int, sprintf_int_8);
  tcase_add_test(sprintf_int, sprintf_int_9);

  TCase *sprintf_float = tcase_create("Sprintf_float");
  suite_add_tcase(s1, sprintf_float);
  tcase_add_test(sprintf_float, sprintf_float_flags);
  tcase_add_test(sprintf_float, sprintf_float_0);
  tcase_add_test(sprintf_float, sprintf_float_1);
  tcase_add_test(sprintf_float, sprintf_float_2);
  tcase_add_test(sprintf_float, sprintf_float_3);
  tcase_add_test(sprintf_float, sprintf_float_4);
  tcase_add_test(sprintf_float, sprintf_float_5);
  tcase_add_test(sprintf_float, sprintf_float_6);
  tcase_add_test(sprintf_float, sprintf_float_7);
  tcase_add_test(sprintf_float, sprintf_float_8);
  tcase_add_test(sprintf_float, sprintf_float_9);
  tcase_add_test(sprintf_float, sprintf_float_10);
  tcase_add_test(sprintf_float, sprintf_float_11);
  tcase_add_test(sprintf_float, sprintf_float_12);

  TCase *sprintf_string = tcase_create("Sprintf_string");
  suite_add_tcase(s1, sprintf_string);
  tcase_add_test(sprintf_string, sprintf_string_flags);
  tcase_add_test(sprintf_string, sprintf_string_0);
  tcase_add_test(sprintf_string, sprintf_string_1);
  tcase_add_test(sprintf_string, sprintf_string_2);
  tcase_add_test(sprintf_string, string);
  tcase_add_test(sprintf_string, string_width);
  tcase_add_test(sprintf_string, string_long);

  TCase *sprintf_percent = tcase_create("Sprintf_percent");
  suite_add_tcase(s1, sprintf_percent);
  tcase_add_test(sprintf_percent, sprintf_percent_0);

  TCase *sprintf_uint = tcase_create("Sprintf_uint");
  suite_add_tcase(s1, sprintf_uint);
  tcase_add_test(sprintf_uint, sprintf_uint_flags);
  tcase_add_test(sprintf_uint, sprintf_uint_0);
  tcase_add_test(sprintf_uint, sprintf_uint_1);
  tcase_add_test(sprintf_uint, sprintf_uint_2);
  tcase_add_test(sprintf_uint, sprintf_uint_3);
  tcase_add_test(sprintf_uint, unsigned_val);
  tcase_add_test(sprintf_uint, unsigned_val_width);
  tcase_add_test(sprintf_uint, unsigned_val_flags);
  tcase_add_test(sprintf_uint, unsigned_val_precision);
  tcase_add_test(sprintf_uint, unsigned_val_many_flags);
  tcase_add_test(sprintf_uint, unsigned_val_short);
  tcase_add_test(sprintf_uint, unsigned_val_long);

  TCase *sprintf_octal = tcase_create("Sprintf_octal");
  suite_add_tcase(s1, sprintf_octal);
  tcase_add_test(sprintf_octal, sprintf_octal_flags);
  tcase_add_test(sprintf_octal, sprintf_octal_0);
  tcase_add_test(sprintf_octal, sprintf_octal_1);
  tcase_add_test(sprintf_octal, sprintf_octal_2);
  tcase_add_test(sprintf_octal, sprintf_octal_3);
  tcase_add_test(sprintf_octal, sprintf_octal_4);
  tcase_add_test(sprintf_octal, sprintf_octal_5);
  tcase_add_test(sprintf_octal, sprintf_octal_6);
  tcase_add_test(sprintf_octal, sprintf_octal_7);
  tcase_add_test(sprintf_octal, sprintf_octal_8);
  tcase_add_test(sprintf_octal, sprintf_octal_9);
  tcase_add_test(sprintf_octal, sprintf_octal_10);

  TCase *sprintf_hex = tcase_create("Sprintf_hex");
  suite_add_tcase(s1, sprintf_hex);
  tcase_add_test(sprintf_hex, sprintf_hex_flags_1);
  tcase_add_test(sprintf_hex, sprintf_hex_flags_2);
  tcase_add_test(sprintf_hex, hex_width);
  tcase_add_test(sprintf_hex, hex_precision);
  tcase_add_test(sprintf_hex, hex_zero);

  TCase *sprintf_ptr = tcase_create("Sprintf_ptr");
  suite_add_tcase(s1, sprintf_ptr);
  tcase_add_test(sprintf_ptr, sprintf_ptr_0);
  tcase_add_test(sprintf_ptr, sprintf_ptr_1);

  TCase *sprintf_sci = tcase_create("Sprintf_sci");
  suite_add_tcase(s1, sprintf_sci);
  tcase_add_test(sprintf_sci, sprintf_sci_flags_1);
  tcase_add_test(sprintf_sci, sprintf_sci_flags_2);
  tcase_add_test(sprintf_sci, sprintf_sci_0);
  tcase_add_test(sprintf_sci, sprintf_sci_1);

  return s1;
}