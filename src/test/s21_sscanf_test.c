#include "test.h"

void double_eq(double x1, double x2) {
  int test = (fabs(x1 - x2) < 1e-6);
  ck_assert(test);
}

// char
START_TEST(sscanf_char_0) {
  char s21_c = 0, c = 0;
  char string[512];
  char format[512];

  strcpy(string, "R");
  strcpy(format, "%c");

  int s21_n = s21_sscanf(string, format, &s21_c);
  int n = sscanf(string, format, &c);

  ck_assert_int_eq(s21_c, c);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_1) {
  char s21_c = 0, c = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello");
  strcpy(format, "%c");

  int s21_n = s21_sscanf(string, format, &s21_c);
  int n = sscanf(string, format, &c);

  ck_assert_int_eq(s21_c, c);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_2) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello batya");
  strcpy(format, "%cello %catya");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_3) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello batya");
  strcpy(format, "%c%catya");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_4) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "       Hello batya");
  strcpy(format, "%c%catya");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_5) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello\nbatya");
  strcpy(format, "Hello %c%ctya");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_6) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello batya");
  strcpy(format, "Hellotya%c%c");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_7) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello batya");
  strcpy(format, "%c%c");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_8) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "  ");
  strcpy(format, "%c%c");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_9) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "\n\n");
  strcpy(format, "%c%c");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_10) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "\n\n");
  strcpy(format, "%c %c");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_11) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "  ");
  strcpy(format, "%c\n%c");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_12) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "");
  strcpy(format, "%c\n%c");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_13) {
  char s21_c0 = 0, s21_c1 = 0, c0 = 0, c1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello  ");
  strcpy(format, "Hello%c%c");

  int s21_n = s21_sscanf(string, format, &s21_c0, &s21_c1);
  int n = sscanf(string, format, &c0, &c1);

  ck_assert_int_eq(s21_c0, c0);
  ck_assert_int_eq(s21_c1, c1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_14) {
  char s21_c = 0, c = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello School 21");
  strcpy(format, "Hello %*c%c");

  int s21_n = s21_sscanf(string, format, &s21_c);
  int n = sscanf(string, format, &c);

  ck_assert_int_eq(s21_c, c);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_15) {
  char s21_c = 0, c = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello School 21");
  strcpy(format, "Hello%c%*c");

  int s21_n = s21_sscanf(string, format, &s21_c);
  int n = sscanf(string, format, &c);

  ck_assert_int_eq(s21_c, c);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_char_16) {
  char s21_c = 0, c = 0;
  char string[512];
  char format[512];

  strcpy(string, "HelloME1");
  strcpy(format, "Hello%*c%*c%c");

  int s21_n = s21_sscanf(string, format, &s21_c);
  int n = sscanf(string, format, &c);

  ck_assert_int_eq(s21_c, c);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

// int_d
START_TEST(sscanf_int_d_0) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello 1984");
  strcpy(format, "Hello %d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_1) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello1984");
  strcpy(format, "Hello%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_2) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello19 84");
  strcpy(format, "Hello19%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_3) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "");
  strcpy(format, "%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_4) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "-2147483648");
  strcpy(format, "%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_5) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "2147483647");
  strcpy(format, "%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_6) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "       2147647      ");
  strcpy(format, "%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_7) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "\n\n\n2147647      ");
  strcpy(format, "         %d\n\n\n");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_8) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "2147647 -1984");
  strcpy(format, "%d %d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_9) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-0-0");
  strcpy(format, "%d %d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_10) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "198-987");
  strcpy(format, "%d %d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_11) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "Hello 198-987");
  strcpy(format, "Hello%d %d and what next?");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_12) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "1y7");
  strcpy(format, "%d %d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_13) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-871249\n\n\n\n871263");
  strcpy(format, "%d%d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_14) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-871249\n\n\n\n871263      8971234");
  strcpy(format, "%d%*d%d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_15) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-871249\n\n\n\n871263      8971234");
  strcpy(format, "%*d%d%d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_16) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-871249\n\n\n\n871263      8971234");
  strcpy(format, "%d%d%*d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_17) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-87189712");
  strcpy(format, "%5d%6d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_18) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-87189712");
  strcpy(format, "%2d%d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_19) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-8719712");
  strcpy(format, "%d%d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_20) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-12");
  strcpy(format, "%2d%1d");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_21) {
  short int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "32767–32768");
  strcpy(format, "%hd%hd");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_d_22) {
  long int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "9223372036854775807-9223372036854775807");
  strcpy(format, "%ld%ld");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

// int_i
START_TEST(sscanf_int_i_0) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "2147483647");
  strcpy(format, "%i");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_1) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "-2147483648");
  strcpy(format, "%i");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_2) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "0x1984");
  strcpy(format, "%i");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_3) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "-0XABCDEF");
  strcpy(format, "%i");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_4) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "-0xabcdef");
  strcpy(format, "%i");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_5) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "00x0");
  strcpy(format, "%i%i");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_6) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "000x0");
  strcpy(format, "%i%i");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_7) {
  int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "010x2");
  strcpy(format, "%2i%3i");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_8) {
  unsigned int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "0x19867 0124537");
  strcpy(format, "%12i%i");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_9) {
  long s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "0x198670124537");
  strcpy(format, "%7li%li");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_i_10) {
  long s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "-00001234123123123123123");
  strcpy(format, "%7li%li");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_o_0) {
  unsigned short s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "123 764");
  strcpy(format, "%ho%ho");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_o_1) {
  unsigned short s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "0123 0x764");
  strcpy(format, "%ho%ho");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_o_2) {
  unsigned int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "01763232345");
  strcpy(format, "%4o%4o");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_o_3) {
  unsigned long s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "0176323203423415");
  strcpy(format, "%8lo%8lo");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_u_0) {
  unsigned short s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "08976 01243");
  strcpy(format, "%hu%hu");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_u_1) {
  unsigned short s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "65535 065535");
  strcpy(format, "%hu%hu");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_u_2) {
  unsigned int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "4294967295 0004294967295");
  strcpy(format, "%u%u");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_u_3) {
  unsigned long s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "18446744073709551615 0018446744073709551615");
  strcpy(format, "%lu%lu");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_xX_0) {
  unsigned short s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "123 456");
  strcpy(format, "%hx%hX");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_xX_1) {
  unsigned int s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "0x123 042faB6");
  strcpy(format, "%x%X");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_xX_2) {
  unsigned long s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "0x12abcdEf0x30x42faB6");
  strcpy(format, "%10lx%10lX");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_int_xX_3) {
  unsigned long s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "0x0 0x0");
  strcpy(format, "%10lx%10lX");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  ck_assert_int_eq(s21_x0, x0);
  ck_assert_int_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

// float
START_TEST(sscanf_float_0) {
  float s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "10.123 -983.8732");
  strcpy(format, "%f %f");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  double_eq(s21_x0, x0);
  double_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_float_1) {
  float s21_x0 = 0, s21_x1 = 0, x0 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "10.123e-4 -983.8732");
  strcpy(format, "%f %f");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  double_eq(s21_x0, x0);
  double_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_float_2) {
  double s21_x0 = 0, x0 = 0, s21_x1 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "10.123e-4 -983.8732e3");
  strcpy(format, "%le %lE");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  double_eq(s21_x0, x0);
  double_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_float_3) {
  double s21_x0 = 0, x0 = 0, s21_x1 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "10.123e-4 -983.8732e3");
  strcpy(format, "%lg %lG");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  double_eq(s21_x0, x0);
  double_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_float_4) {
  long double s21_x0 = 0, x0 = 0, s21_x1 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "10.123e-140 -0.000000000000000008732e14");
  strcpy(format, "%Lg %LG");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  double_eq(s21_x0, x0);
  double_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_float_5) {
  long double s21_x0 = 0, x0 = 0, s21_x1 = 0, x1 = 0;
  char string[512];
  char format[512];

  strcpy(string, "10.123e-140 -0.000000000000000008732e14");
  strcpy(format, "%Le %LE");

  int s21_n = s21_sscanf(string, format, &s21_x0, &s21_x1);
  int n = sscanf(string, format, &x0, &x1);

  double_eq(s21_x0, x0);
  double_eq(s21_x1, x1);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_float_6) {
  long double s21_x0 = 0, x0 = 0;
  char string[512];
  char format[512];

  strcpy(string, "10.123e-140 -0.000000000000000008732e14");
  strcpy(format, "%*Lf %Lf");

  int s21_n = s21_sscanf(string, format, &s21_x0);
  int n = sscanf(string, format, &x0);

  double_eq(s21_x0, x0);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

// String
START_TEST(sscanf_string_0) {
  char s21_str[512], str[512];
  char string[512];
  char format[512];

  strcpy(string, "I want to say hello");
  strcpy(format, "%s");

  int s21_n = s21_sscanf(string, format, s21_str);
  int n = sscanf(string, format, str);

  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_string_1) {
  char s21_str1[512], str1[512], s21_str2[512], str2[512];
  char string[512];
  char format[512];

  strcpy(string, "I want to say hello to all my friends and enemies");
  strcpy(format, "%20s %s");

  int s21_n = s21_sscanf(string, format, s21_str1, s21_str2);
  int n = sscanf(string, format, str1, str2);

  ck_assert_str_eq(s21_str1, str1);
  ck_assert_str_eq(s21_str2, str2);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_string_2) {
  char s21_str1[512], str1[512], s21_str2[512], str2[512];
  char string[512];
  char format[512];

  strcpy(string, "I want to say hello to all my friends and enemies");
  strcpy(format, "I want to %s hello to all my %s");

  int s21_n = s21_sscanf(string, format, s21_str1, s21_str2);
  int n = sscanf(string, format, str1, str2);

  ck_assert_str_eq(s21_str1, str1);
  ck_assert_str_eq(s21_str2, str2);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_string_3) {
  char s21_str1[512], str1[512], s21_str2[512], str2[512];
  char string[512];
  char format[512];

  strcpy(string, "I want to say hello to all my friends and enemies");
  strcpy(format, "I want to%s hello to all my%s");

  int s21_n = s21_sscanf(string, format, s21_str1, s21_str2);
  int n = sscanf(string, format, str1, str2);

  ck_assert_str_eq(s21_str1, str1);
  ck_assert_str_eq(s21_str2, str2);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

// pointer
START_TEST(sscanf_pointer_0) {
  void *s21_p = 0, *p = 0;
  char string[512];
  char format[512];

  strcpy(string, "1243453");
  strcpy(format, "%p");

  int s21_n = s21_sscanf(string, format, &s21_p);
  int n = sscanf(string, format, &p);

  ck_assert_ptr_eq(s21_p, p);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_pointer_1) {
  void *s21_p = 0, *p = 0;
  char string[512];
  char format[512];

  strcpy(string, "01243453");
  strcpy(format, "%p");

  int s21_n = s21_sscanf(string, format, &s21_p);
  int n = sscanf(string, format, &p);

  ck_assert_ptr_eq(s21_p, p);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_pointer_2) {
  void *s21_p = 0, *p = 0;
  char string[512];
  char format[512];

  strcpy(string, "0x1243453");
  strcpy(format, "%p");

  int s21_n = s21_sscanf(string, format, &s21_p);
  int n = sscanf(string, format, &p);

  ck_assert_ptr_eq(s21_p, p);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_pointer_3) {
  void *s21_p1 = 0, *p1 = 0, *s21_p2 = 0, *p2 = 0;
  char string[512];
  char format[512];

  strcpy(string, "0x1243453");
  strcpy(format, "%4p%p");

  int s21_n = s21_sscanf(string, format, &s21_p1, &s21_p2);
  int n = sscanf(string, format, &p1, &p2);

  ck_assert_ptr_eq(s21_p1, p1);
  ck_assert_ptr_eq(s21_p2, p2);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_pointer_4) {
  void *s21_p = 0, *p = 0;
  char string[512];
  char format[512];

  strcpy(string, "-0xabcdef");
  strcpy(format, "%p");

  int s21_n = s21_sscanf(string, format, &s21_p);
  int n = sscanf(string, format, &p);

  ck_assert_ptr_eq(s21_p, p);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_pointer_5) {
  void *s21_p = 0, *p = 0;
  char string[512];
  char format[512];

  strcpy(string, "-0xABCDEF");
  strcpy(format, "%p");

  int s21_n = s21_sscanf(string, format, &s21_p);
  int n = sscanf(string, format, &p);

  ck_assert_ptr_eq(s21_p, p);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

// other
START_TEST(sscanf_other_0) {
  char s21_str[512], str[512];
  char string[512];
  char format[512];

  strcpy(string, "I want to % hello to all my friends and enemies");
  strcpy(format, "I want to %% hello to all my%s");

  int s21_n = s21_sscanf(string, format, s21_str);
  int n = sscanf(string, format, str);

  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_other_1) {
  char s21_str[512], str[512];
  char string[512];
  char format[512];

  strcpy(string, "I want to %% hello to all my friends and enemies");
  strcpy(format, "I want to %%%% hello to all my%s");

  int s21_n = s21_sscanf(string, format, s21_str);
  int n = sscanf(string, format, str);

  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_other_2) {
  char s21_str[512], str[512];
  char string[512];
  char format[512];

  strcpy(string, "I want to % % hello to all my friends and enemies");
  strcpy(format, "I want to %% %% hello to all my%s");

  int s21_n = s21_sscanf(string, format, s21_str);
  int n = sscanf(string, format, str);

  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_other_3) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "I want % to say hello to all my  friends and enemies");
  strcpy(format, "I want %% to %*s hello to all my   %n");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_other_4) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "I want % to say hello to all my friends and enemies");
  strcpy(format, "I want %% to %*s hello to all my%n");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_other_5) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "I want % to say hello to all my 10 friends and enemies");
  strcpy(format, "I want %% to %*s hello to all my%*n%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_x, x);
  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_other_6) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "I want % to say hello to all my 10 friends and enemies");
  strcpy(format, "I want %% to %*s hello to all my%*n%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_n, n);
}
END_TEST

START_TEST(sscanf_other_7) {
  int s21_x = 0, x = 0;
  char string[512];
  char format[512];

  strcpy(string, "I want  to say hello to all my 10 friends and enemies");
  strcpy(format, "I want %% to %*s hello to all my%*n%d");

  int s21_n = s21_sscanf(string, format, &s21_x);
  int n = sscanf(string, format, &x);

  ck_assert_int_eq(s21_n, n);
}
END_TEST

Suite *s21_sscanf_test(void) {
  Suite *s1 = suite_create("Core");

  TCase *sscanf_char = tcase_create("Sscanf_char");
  suite_add_tcase(s1, sscanf_char);
  tcase_add_test(sscanf_char, sscanf_char_0);
  tcase_add_test(sscanf_char, sscanf_char_1);
  tcase_add_test(sscanf_char, sscanf_char_2);
  tcase_add_test(sscanf_char, sscanf_char_3);
  tcase_add_test(sscanf_char, sscanf_char_4);
  tcase_add_test(sscanf_char, sscanf_char_5);
  tcase_add_test(sscanf_char, sscanf_char_6);
  tcase_add_test(sscanf_char, sscanf_char_7);
  tcase_add_test(sscanf_char, sscanf_char_8);
  tcase_add_test(sscanf_char, sscanf_char_9);
  tcase_add_test(sscanf_char, sscanf_char_10);
  tcase_add_test(sscanf_char, sscanf_char_11);
  tcase_add_test(sscanf_char, sscanf_char_12);
  tcase_add_test(sscanf_char, sscanf_char_13);
  tcase_add_test(sscanf_char, sscanf_char_14);
  tcase_add_test(sscanf_char, sscanf_char_15);
  tcase_add_test(sscanf_char, sscanf_char_16);

  TCase *sscanf_int = tcase_create("Sscanf_int");
  suite_add_tcase(s1, sscanf_int);
  tcase_add_test(sscanf_int, sscanf_int_d_0);
  tcase_add_test(sscanf_int, sscanf_int_d_1);
  tcase_add_test(sscanf_int, sscanf_int_d_2);
  tcase_add_test(sscanf_int, sscanf_int_d_3);
  tcase_add_test(sscanf_int, sscanf_int_d_4);
  tcase_add_test(sscanf_int, sscanf_int_d_5);
  tcase_add_test(sscanf_int, sscanf_int_d_6);
  tcase_add_test(sscanf_int, sscanf_int_d_7);
  tcase_add_test(sscanf_int, sscanf_int_d_8);
  tcase_add_test(sscanf_int, sscanf_int_d_9);
  tcase_add_test(sscanf_int, sscanf_int_d_10);
  tcase_add_test(sscanf_int, sscanf_int_d_11);
  tcase_add_test(sscanf_int, sscanf_int_d_12);
  tcase_add_test(sscanf_int, sscanf_int_d_13);
  tcase_add_test(sscanf_int, sscanf_int_d_14);
  tcase_add_test(sscanf_int, sscanf_int_d_15);
  tcase_add_test(sscanf_int, sscanf_int_d_16);
  tcase_add_test(sscanf_int, sscanf_int_d_17);
  tcase_add_test(sscanf_int, sscanf_int_d_18);
  tcase_add_test(sscanf_int, sscanf_int_d_19);
  tcase_add_test(sscanf_int, sscanf_int_d_20);
  tcase_add_test(sscanf_int, sscanf_int_d_21);
  tcase_add_test(sscanf_int, sscanf_int_d_22);

  tcase_add_test(sscanf_int, sscanf_int_i_0);
  tcase_add_test(sscanf_int, sscanf_int_i_1);
  tcase_add_test(sscanf_int, sscanf_int_i_2);
  tcase_add_test(sscanf_int, sscanf_int_i_3);
  tcase_add_test(sscanf_int, sscanf_int_i_4);
  tcase_add_test(sscanf_int, sscanf_int_i_5);
  tcase_add_test(sscanf_int, sscanf_int_i_6);
  tcase_add_test(sscanf_int, sscanf_int_i_7);
  tcase_add_test(sscanf_int, sscanf_int_i_8);
  tcase_add_test(sscanf_int, sscanf_int_i_9);
  tcase_add_test(sscanf_int, sscanf_int_i_10);

  tcase_add_test(sscanf_int, sscanf_int_o_0);
  tcase_add_test(sscanf_int, sscanf_int_o_1);
  tcase_add_test(sscanf_int, sscanf_int_o_2);
  tcase_add_test(sscanf_int, sscanf_int_o_3);

  tcase_add_test(sscanf_int, sscanf_int_u_0);
  tcase_add_test(sscanf_int, sscanf_int_u_1);
  tcase_add_test(sscanf_int, sscanf_int_u_2);
  tcase_add_test(sscanf_int, sscanf_int_u_3);

  tcase_add_test(sscanf_int, sscanf_int_xX_0);
  tcase_add_test(sscanf_int, sscanf_int_xX_1);
  tcase_add_test(sscanf_int, sscanf_int_xX_2);
  tcase_add_test(sscanf_int, sscanf_int_xX_3);

  TCase *sscanf_float = tcase_create("Sscanf_float");
  suite_add_tcase(s1, sscanf_float);
  tcase_add_test(sscanf_float, sscanf_float_0);
  tcase_add_test(sscanf_float, sscanf_float_1);
  tcase_add_test(sscanf_float, sscanf_float_2);
  tcase_add_test(sscanf_float, sscanf_float_3);
  tcase_add_test(sscanf_float, sscanf_float_4);
  tcase_add_test(sscanf_float, sscanf_float_5);
  tcase_add_test(sscanf_float, sscanf_float_6);

  TCase *sscanf_string = tcase_create("Sscanf_string");
  suite_add_tcase(s1, sscanf_string);
  tcase_add_test(sscanf_string, sscanf_string_0);
  tcase_add_test(sscanf_string, sscanf_string_1);
  tcase_add_test(sscanf_string, sscanf_string_2);
  tcase_add_test(sscanf_string, sscanf_string_3);

  TCase *sscanf_pointer = tcase_create("Sscanf_pointer");
  suite_add_tcase(s1, sscanf_pointer);
  tcase_add_test(sscanf_pointer, sscanf_pointer_0);
  tcase_add_test(sscanf_pointer, sscanf_pointer_1);
  tcase_add_test(sscanf_pointer, sscanf_pointer_2);
  tcase_add_test(sscanf_pointer, sscanf_pointer_3);
  tcase_add_test(sscanf_pointer, sscanf_pointer_4);
  tcase_add_test(sscanf_pointer, sscanf_pointer_5);

  TCase *sscanf_other = tcase_create("Sscanf_other");
  suite_add_tcase(s1, sscanf_other);
  tcase_add_test(sscanf_other, sscanf_other_0);
  tcase_add_test(sscanf_other, sscanf_other_1);
  tcase_add_test(sscanf_other, sscanf_other_2);
  tcase_add_test(sscanf_other, sscanf_other_3);
  tcase_add_test(sscanf_other, sscanf_other_4);
  tcase_add_test(sscanf_other, sscanf_other_5);
  tcase_add_test(sscanf_other, sscanf_other_6);
  tcase_add_test(sscanf_other, sscanf_other_7);

  return s1;
}