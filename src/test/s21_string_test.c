#include "test.h"

// MEMCHR
START_TEST(s21_memchr_0) {
  char str[] = "Hello School_21!";

  ck_assert_ptr_eq(s21_memchr(str, str[6], 7), memchr(str, str[6], 7));
  ck_assert_ptr_eq(s21_memchr(str, str[6], 6), memchr(str, str[6], 6));
  ck_assert_ptr_eq(s21_memchr(str, str[0], 0), memchr(str, str[0], 0));
  ck_assert_ptr_eq(s21_memchr(str, str[0], 1), memchr(str, str[0], 1));
  ck_assert_ptr_eq(s21_memchr(str, str[15], 16), memchr(str, str[15], 16));
  ck_assert_ptr_eq(s21_memchr(str, str[15], 17), memchr(str, str[15], 17));
  ck_assert_ptr_eq(s21_memchr(str, str[15], 205), memchr(str, str[15], 205));
  ck_assert_ptr_eq(s21_memchr(str, '\0', 205), memchr(str, '\0', 205));
}
END_TEST

START_TEST(s21_memchr_1) {
  char str[] = " ";

  ck_assert_ptr_eq(s21_memchr(str, str[0], 1), memchr(str, str[0], 1));
  ck_assert_ptr_eq(s21_memchr(str, str[0], 0), memchr(str, str[0], 0));
  ck_assert_ptr_eq(s21_memchr(str, 'T', 1), memchr(str, 'T', 1));
}
END_TEST

START_TEST(s21_memchr_2) {
  char str[] = "";

  ck_assert_ptr_eq(s21_memchr(str, '\0', 0), memchr(str, '\0', 0));
  ck_assert_ptr_eq(s21_memchr(str, '\0', 1), memchr(str, '\0', 1));
}
END_TEST

// MEMCPY
START_TEST(s21_memcpy_0) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char str2[] = "abcdefghijklmnopqrstuvwxyz";

  char *pdest1 = &(str1[0]);
  char *pdest2 = &(str2[0]);
  char *psrc1 = &(str1[10]);
  char *psrc2 = &(str2[10]);

  s21_memcpy(pdest1, psrc1, 5);
  memcpy(pdest2, psrc2, 5);
  ck_assert_int_eq(memcmp(pdest1, pdest2, 5), 0);

  s21_memmove(pdest1, psrc1, 9);
  memmove(pdest2, psrc2, 9);
  ck_assert_int_eq(memcmp(pdest1, pdest2, 9), 0);
}
END_TEST

// MEMCMP
START_TEST(s21_memcmp_0) {
  char str1[] = "Hello School_21!";
  char str2[] = "Hello School_22!";

  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 7), memcmp(str1, str2, 7));
  ck_assert_int_eq(s21_memcmp(str1, str2, 15), memcmp(str1, str2, 15));
  ck_assert_int_eq(s21_memcmp(str1, str2, 16), memcmp(str1, str2, 16));
}
END_TEST

START_TEST(s21_memcmp_1) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
}
END_TEST

START_TEST(s21_memcmp_2) {
  char str1[] = "Shia Labeouf";
  char str2[] = "Shia La";

  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
  ck_assert_int_eq(s21_memcmp(str1, str2, 7), memcmp(str1, str2, 7));
  ck_assert_int_eq(s21_memcmp(str1, str2, 8), memcmp(str1, str2, 8));
}
END_TEST

START_TEST(s21_memcmp_3) {
  char str1[] = "Shia Labeouf";
  char str2[] = "Shia Landar";

  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
  ck_assert_int_eq(s21_memcmp(str1, str2, 7), memcmp(str1, str2, 7));
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
}
END_TEST

// MEMMOVE
START_TEST(s21_memmove_0) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char str2[] = "abcdefghijklmnopqrstuvwxyz";

  char *pdest1 = &(str1[0]);
  char *pdest2 = &(str2[0]);
  char *psrc1 = &(str1[10]);
  char *psrc2 = &(str2[10]);

  s21_memmove(pdest1, psrc1, 5);
  memmove(pdest2, psrc2, 5);
  ck_assert_int_eq(memcmp(pdest1, pdest2, 5), 0);

  s21_memmove(pdest1, psrc1, 15);
  memmove(pdest2, psrc2, 15);
  ck_assert_int_eq(memcmp(pdest1, pdest2, 15), 0);

  s21_memmove(pdest1, psrc1, 10);
  memmove(pdest2, psrc2, 10);
  ck_assert_int_eq(memcmp(pdest1, pdest2, 10), 0);
}
END_TEST

START_TEST(s21_memmove_1) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char str2[] = "abcdefghijklmnopqrstuvwxyz";

  char *pdest1 = &(str1[10]);
  char *pdest2 = &(str2[10]);
  char *psrc1 = &(str1[0]);
  char *psrc2 = &(str2[0]);

  s21_memmove(pdest1, psrc1, 5);
  memmove(pdest2, psrc2, 5);
  ck_assert_int_eq(memcmp(pdest1, pdest2, 5), 0);

  s21_memmove(pdest1, psrc1, 15);
  memmove(pdest2, psrc2, 15);
  ck_assert_int_eq(memcmp(pdest1, pdest2, 15), 0);

  s21_memmove(pdest1, psrc1, 10);
  memmove(pdest2, psrc2, 10);
  ck_assert_int_eq(memcmp(pdest1, pdest2, 10), 0);
}
END_TEST

START_TEST(s21_memmove_2) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";

  char *pdest1 = &(str1[10]);
  char *psrc1 = &(str1[0]);

  ck_assert_ptr_eq(s21_memmove(NULL, psrc1, 5), NULL);
  ck_assert_ptr_eq(s21_memmove(pdest1, NULL, 5), NULL);
}
END_TEST

// MEMSET
START_TEST(s21_memset_0) {
  char str[512] = "Hello School_21!!!";
  char s21_str[512];
  s21_strcpy(s21_str, str);

  ck_assert_str_eq(s21_memset(s21_str, 'X', 1), memset(str, 'X', 1));
  ck_assert_str_eq(s21_memset(s21_str, 'X', 3), memset(str, 'X', 3));
  ck_assert_str_eq(s21_memset(s21_str, 'X', 18), memset(str, 'X', 18));
}
END_TEST

START_TEST(s21_memset_1) {
  char str1[] = "Hello School_21!!!";
  char str2[] = "Hello School_21!!!";

  ck_assert(!s21_memcmp(s21_memset(str1, 'X', 2), memset(str2, 'X', 2),
                        s21_strlen(str1)));
}
END_TEST

// STRNCAT
START_TEST(s21_strncat_0) {
  char s21_dest[10] = "";
  char dest[10] = "";
  char src[10] = "1 2 3";

  ck_assert_str_eq(strncat(dest, src, 5), s21_strncat(s21_dest, src, 5));
}
END_TEST

START_TEST(s21_strncat_1) {
  char s21_dest[10] = "111\n";
  char dest[10] = "111\n";
  char src[10] = "1 2 3";

  ck_assert_str_eq(strncat(dest, src, 3), s21_strncat(s21_dest, src, 3));
}
END_TEST

START_TEST(s21_strncat_2) {
  char s21_dest[12] = "";
  char dest[12] = "";
  char src[11] = "1 2 3 4 5 6";

  ck_assert_str_eq(strncat(dest, src, 11), s21_strncat(s21_dest, src, 11));
}
END_TEST

// STRCAT
START_TEST(s21_strcat_0) {
  char s21_dest[10] = "";
  char dest[10] = "";
  char src[10] = "1 2 3";

  ck_assert_str_eq(strcat(dest, src), s21_strcat(s21_dest, src));
}
END_TEST

START_TEST(s21_strcat_1) {
  char s21_dest[10] = "\0";
  char dest[10] = "\0";
  char src[10] = "1 2 3";

  ck_assert_str_eq(strcat(dest, src), s21_strcat(s21_dest, src));
}
END_TEST

START_TEST(s21_strcat_2) {
  char s21_dest[10] = "123";
  char dest[10] = "123";
  char src[10] = "1 2 3";

  ck_assert_str_eq(strcat(dest, src), s21_strcat(s21_dest, src));
}
END_TEST

// STRCHR
START_TEST(s21_strchr_0) {
  char str[] = "Hello School_21!";

  ck_assert_ptr_eq(strchr(str, str[0]), s21_strchr(str, str[0]));
  ck_assert_ptr_eq(strchr(str, str[3]), s21_strchr(str, str[3]));
  ck_assert_ptr_eq(strchr("", '\0'), s21_strchr("", '\0'));
  ck_assert_ptr_eq(strchr("", 'a'), s21_strchr("", 'a'));
  ck_assert_ptr_eq(strchr(str, 'q'), s21_strchr(str, 'q'));
  ck_assert_ptr_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

// STRCMP
START_TEST(s21_strcmp_0) {
  char str1[] = "Hello School_21!";
  char str2[] = "Hello ";
  char str3[] = "";
  char str4[] = "Hello School_21?";

  ck_assert_int_eq(strcmp(str1, str2) > 0, s21_strcmp(str1, str2) > 0);
  ck_assert_int_eq(strcmp(str2, str1) < 0, s21_strcmp(str2, str1) < 0);
  ck_assert_int_eq(strcmp(str1, str1) == 0, s21_strcmp(str1, str1) == 0);
  ck_assert_int_eq(strcmp(str3, str3) == 0, s21_strcmp(str3, str3) == 0);
  ck_assert_int_eq(strcmp(str2, str3) > 0, s21_strcmp(str2, str3) > 0);
  ck_assert_int_eq(strcmp(str3, str1) < 0, s21_strcmp(str3, str1) < 0);
  ck_assert_int_eq(strcmp(str4, str1) < 0, s21_strcmp(str4, str1) < 0);
  ck_assert_int_eq(strcmp(str4, str1) == 0, s21_strcmp(str4, str1) == 0);
}
END_TEST

// STRNCMP
START_TEST(s21_strncmp_0) {
  char str1[] = "Hello School_21!";
  char str2[] = "Hello ";
  char str3[] = "";
  char str4[] = "Hello School_21?";

  ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));
  ck_assert_int_eq(strncmp(str1, str2, 10) < 0,
                   s21_strncmp(str1, str2, 10) < 0);
  ck_assert_int_eq(strncmp(str1, str2, 10) > 0,
                   s21_strncmp(str1, str2, 10) > 0);
  ck_assert_int_eq(strncmp(str1, str2, 200) < 0,
                   s21_strncmp(str1, str2, 200) < 0);
  ck_assert_int_eq(strncmp(str1, str2, 200) > 0,
                   s21_strncmp(str1, str2, 200) > 0);
  ck_assert_int_eq(strncmp(str1, str3, 0) < 0, s21_strncmp(str1, str3, 0) < 0);
  ck_assert_int_eq(strncmp(str1, str3, 0) > 0, s21_strncmp(str1, str3, 0) > 0);

  ck_assert_int_eq(strncmp(str1, str4, 15) < 0,
                   s21_strncmp(str1, str4, 15) < 0);
  ck_assert_int_eq(strncmp(str1, str4, 15) > 0,
                   s21_strncmp(str1, str4, 15) > 0);
  ck_assert_int_eq(strncmp(str1, str4, 16) < 0,
                   s21_strncmp(str1, str4, 16) < 0);
  ck_assert_int_eq(strncmp(str1, str4, 16) > 0,
                   s21_strncmp(str1, str4, 16) > 0);
}
END_TEST

// STRCPY
START_TEST(s21_strcpy_0) {
  char dest[16];
  char dest_true[16];
  char src1[] = "Hell0";
  char src2[] = "";
  char src3[] = "one more test";

  ck_assert_str_eq(strcpy(dest_true, src1), s21_strcpy(dest, src1));
  ck_assert_str_eq(strcpy(dest_true, src2), s21_strcpy(dest, src2));
  ck_assert_str_eq(strcpy(dest_true, src3), s21_strcpy(dest, src3));
}
END_TEST

// STRNCPY
START_TEST(s21_strncpy_0) {
  char dest[16];
  char dest_true[16];
  char src1[] = "Hell0";
  char src2[] = "";
  char src3[] = "one more test";

  ck_assert_str_eq(strncpy(dest_true, src1, 6), s21_strncpy(dest, src1, 6));
  ck_assert_str_eq(strncpy(dest_true, src2, 3), s21_strncpy(dest, src2, 3));
  ck_assert_str_eq(strncpy(dest_true, src3, 16), s21_strncpy(dest, src3, 16));
}
END_TEST

// STRCSPN
START_TEST(s21_strcspn_0) {
  char str[16] = "Hello everyone";

  ck_assert_int_eq(strcspn(str, "llv"), s21_strcspn(str, "llv"));
  ck_assert_int_eq(strcspn(str, "one"), s21_strcspn(str, "one"));
  ck_assert_int_eq(strcspn(str, "Hell"), s21_strcspn(str, "Hell"));
  ck_assert_int_eq(strcspn(str, "qz"), s21_strcspn(str, "qz"));
  ck_assert_int_eq(strcspn(str, ""), s21_strcspn(str, ""));
  ck_assert_int_eq(strcspn(str, ","), s21_strcspn(str, ","));
  ck_assert_int_eq(strcspn("", "123"), s21_strcspn("", "123"));
  ck_assert_int_eq(strcspn("", "qz"), s21_strcspn("", "qz"));
}
END_TEST

// STRERROR
START_TEST(s21_strerror_0) {
  for (int errnum = -10; errnum < MAX_ERROR_CODE + 10; errnum++) {
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
  }
}
END_TEST

// STRPBRK
START_TEST(s21_strpbrk_0) {
  char str[16] = "Hello everyone";

  ck_assert_ptr_eq(strpbrk(str, "no"), s21_strpbrk(str, "no"));
  ck_assert_ptr_eq(strpbrk(str, "Hello"), s21_strpbrk(str, "Hello"));
  ck_assert_ptr_eq(strpbrk(str, "xaf"), s21_strpbrk(str, "xaf"));
  ck_assert_ptr_eq(strpbrk(str, "\0\0"), s21_strpbrk(str, "\0\0"));
  ck_assert_ptr_eq(strpbrk(str, "\0H"), s21_strpbrk(str, "\0H"));
  ck_assert_ptr_eq(strpbrk("", "\0"), s21_strpbrk("", "\0"));
  ck_assert_ptr_eq(strpbrk("", "abc"), s21_strpbrk("", "abc"));
}
END_TEST

// STRRCHR
START_TEST(s21_strrchr_0) {
  char str[] = "Hello School_21!";

  ck_assert_ptr_eq(strrchr(str, str[0]), s21_strrchr(str, str[0]));
  ck_assert_ptr_eq(strrchr(str, str[6]), s21_strrchr(str, str[6]));
  ck_assert_ptr_eq(strrchr(str, str[16]), s21_strrchr(str, str[16]));
  ck_assert_ptr_eq(strrchr(str, str[2]), s21_strrchr(str, str[2]));
  ck_assert_ptr_eq(strrchr(str, 'q'), s21_strrchr(str, 'q'));
  ck_assert_ptr_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
  ck_assert_ptr_eq(strrchr("", str[2]), s21_strrchr("", str[2]));
  ck_assert_ptr_eq(strrchr("", '\0'), s21_strrchr("", '\0'));
}
END_TEST

// STRSPN
START_TEST(s21_strspn_0) {
  char str[16] = "Hello everyone";

  ck_assert_int_eq(strspn(str, str), s21_strspn(str, str));
  ck_assert_int_eq(strspn(str, "llv"), s21_strspn(str, "llv"));
  ck_assert_int_eq(strspn(str, "one"), s21_strspn(str, "one"));
  ck_assert_int_eq(strspn(str, "Hell"), s21_strspn(str, "Hell"));
  ck_assert_int_eq(strspn(str, "qz"), s21_strspn(str, "qz"));
  ck_assert_int_eq(strspn(str, ""), s21_strspn(str, ""));
  ck_assert_int_eq(strspn("", "qz"), s21_strspn("", "qz"));
  ck_assert_int_eq(strspn("", ""), s21_strspn("", ""));
}
END_TEST

// STRSTR
START_TEST(s21_strstr_0) {
  char str[32] = "HH Hello Hello everyone!";

  ck_assert_ptr_eq(strstr(str, "Hello "), s21_strstr(str, "Hello "));
  ck_assert_ptr_eq(strstr(str, "H"), s21_strstr(str, "H"));
  ck_assert_ptr_eq(strstr(str, "H "), s21_strstr(str, "H "));
  ck_assert_ptr_eq(strstr(str, ""), s21_strstr(str, ""));
  ck_assert_ptr_eq(strstr(str, "olle"), s21_strstr(str, "olle"));
  ck_assert_ptr_eq(strstr(str, "everyone!"), s21_strstr(str, "everyone!"));
  ck_assert_ptr_eq(strstr(str, "Hello everyone!?"),
                   s21_strstr(str, "Hello everyone!?"));
}
END_TEST

// STRTOK
START_TEST(s21_strtok_0) {
  char str[512] = "HH Hello Hello everyone!";
  char s21_str[512];
  strcpy(s21_str, str);

  ck_assert_str_eq(strtok(str, " "), s21_strtok(s21_str, " "));
  ck_assert_str_eq(strtok(NULL, " "), s21_strtok(NULL, " "));
  ck_assert_str_eq(strtok(NULL, " "), s21_strtok(NULL, " "));
  ck_assert_str_eq(strtok(NULL, " "), s21_strtok(NULL, " "));
  ck_assert_ptr_eq(strtok(NULL, " "), s21_strtok(NULL, " "));
  ck_assert_ptr_eq(strtok(NULL, " "), s21_strtok(NULL, " "));
}
END_TEST

START_TEST(s21_strtok_1) {
  char str[512] = "HH Hello Hello everyone!";
  char s21_str[512];
  strcpy(s21_str, str);

  ck_assert_str_eq(strtok(str, "H"), s21_strtok(s21_str, "H"));
  ck_assert_str_eq(strtok(NULL, "H"), s21_strtok(NULL, "H"));
  ck_assert_str_eq(strtok(NULL, "H"), s21_strtok(NULL, "H"));
  ck_assert_ptr_eq(strtok(NULL, "H"), s21_strtok(NULL, "H"));
  ck_assert_ptr_eq(strtok(NULL, "H"), s21_strtok(NULL, "H"));
  ck_assert_ptr_eq(strtok(NULL, "H"), s21_strtok(NULL, "H"));
}
END_TEST

START_TEST(s21_strtok_2) {
  char str[512] = "HH Hello Hello everyone!";
  char s21_str[512];
  strcpy(s21_str, str);

  ck_assert_str_eq(strtok(str, "H "), s21_strtok(s21_str, "H "));
  ck_assert_str_eq(strtok(NULL, " H"), s21_strtok(NULL, " H"));
  ck_assert_str_eq(strtok(NULL, "H "), s21_strtok(NULL, "H "));
  ck_assert_ptr_eq(strtok(NULL, " H"), s21_strtok(NULL, " H"));
  ck_assert_ptr_eq(strtok(NULL, "H "), s21_strtok(NULL, "H "));
  ck_assert_ptr_eq(strtok(NULL, " H"), s21_strtok(NULL, " H"));
}
END_TEST

START_TEST(s21_strtok_3) {
  char str[512] = "HH Hello Hello everyone!";
  char s21_str[512];
  strcpy(s21_str, str);

  ck_assert_str_eq(strtok(str, "!"), s21_strtok(s21_str, "!"));
  ck_assert_ptr_eq(strtok(NULL, "\0"), s21_strtok(NULL, "\0"));
  ck_assert_ptr_eq(strtok(NULL, "H "), s21_strtok(NULL, "H "));
}
END_TEST

START_TEST(s21_strtok_4) {
  char str[512] = "Balabama";
  char s21_str[512];
  strcpy(s21_str, str);

  ck_assert_str_eq(strtok(str, " "), s21_strtok(s21_str, " "));
  ck_assert_ptr_eq(strtok(NULL, "\0"), s21_strtok(NULL, "\0"));
  ck_assert_ptr_eq(strtok(NULL, "B "), s21_strtok(NULL, "B "));
}
END_TEST

START_TEST(s21_strtok_5) {
  char str[512] = "Balabama";
  char s21_str[512];
  strcpy(s21_str, str);

  ck_assert_str_eq(strtok(str, "\0 "), s21_strtok(s21_str, "\0 "));
  ck_assert_ptr_eq(strtok(NULL, "\0"), s21_strtok(NULL, "\0"));
  ck_assert_ptr_eq(strtok(NULL, "B "), s21_strtok(NULL, "B "));
}
END_TEST

START_TEST(s21_strtok_6) {
  char str[512] = "";
  char s21_str[512];
  strcpy(s21_str, str);

  ck_assert_ptr_eq(strtok(str, "\0 "), s21_strtok(s21_str, "\0 "));
  ck_assert_ptr_eq(strtok(NULL, "\0"), s21_strtok(NULL, "\0"));
  ck_assert_ptr_eq(strtok(NULL, "B "), s21_strtok(NULL, "B "));
}
END_TEST

START_TEST(s21_strtok_7) {
  char str[512] = "Balabama";
  char s21_str[512];
  strcpy(s21_str, str);

  ck_assert_ptr_eq(strtok(str, "Balabama"), s21_strtok(s21_str, "Balabama"));
  ck_assert_ptr_eq(strtok(NULL, " "), s21_strtok(NULL, " "));
  ck_assert_ptr_eq(strtok(NULL, "B "), s21_strtok(NULL, "B "));
}
END_TEST

START_TEST(s21_strtok_8) {
  char str1[512] = "Balabama, how are your grades?";
  char s21_str1[512];
  strcpy(s21_str1, str1);

  char str2[512] = "I have excelent grades!!!";
  char s21_str2[512];
  strcpy(s21_str2, str2);

  ck_assert_str_eq(strtok(str1, " "), s21_strtok(s21_str1, " "));
  ck_assert_str_eq(strtok(str2, " "), s21_strtok(s21_str2, " "));
  ck_assert_str_eq(strtok(NULL, "!"), s21_strtok(NULL, "!"));
}
END_TEST

START_TEST(s21_strtok_9) {
  char str1[512] = "Balabama, how are your grades?";
  char s21_str1[512];
  strcpy(s21_str1, str1);

  char str2[512] = "I have excelent grades!!!";
  char s21_str2[512];
  strcpy(s21_str2, str2);

  ck_assert_str_eq(strtok(str1, " "), s21_strtok(s21_str1, " "));
  ck_assert_str_eq(strtok(NULL, " "), s21_strtok(NULL, " "));
  ck_assert_str_eq(strtok(NULL, " "), s21_strtok(NULL, " "));
  ck_assert_str_eq(strtok(str2, " "), s21_strtok(s21_str2, " "));
  ck_assert_str_eq(strtok(NULL, "!"), s21_strtok(NULL, "!"));
}
END_TEST

// Special functions
START_TEST(s21_to_upper_tests) {
  char test1[20] = "heLLo woRld!!!";
  char *test2 = NULL;
  char etal[20] = "HELLO WORLD!!!";
  char data[20] = "!!!!";
  char *res;

  // test 1
  res = s21_to_upper(test1);
  ck_assert_str_eq(res, etal);
  free(res);

  // test 2
  res = s21_to_upper(etal);
  ck_assert_str_eq(res, etal);
  free(res);

  // test 3
  res = s21_to_upper(data);
  ck_assert_str_eq(res, data);
  free(res);

  // test 4
  res = s21_to_upper(test2);
  ck_assert_ptr_eq(res, NULL);
}
END_TEST

START_TEST(s21_to_lower_tests) {
  char etal[20] = "hello world!!!";
  char test[20] = "HELLO WORLD!!!";
  char *test2 = NULL;
  char data[20] = "!!!!";
  char *res;

  // test 1
  res = s21_to_lower(test);
  ck_assert_str_eq(res, etal);
  free(res);

  // test 2
  res = s21_to_lower(etal);
  ck_assert_str_eq(res, etal);
  free(res);

  // test 3
  res = s21_to_lower(data);
  ck_assert_str_eq(res, data);
  free(res);

  // test 4
  res = s21_to_lower(test2);
  ck_assert_ptr_eq(res, NULL);
}
END_TEST

START_TEST(s21_trim_tests) {
  char str[40] = "*** Much Ado About Nothing ***";
  char *res;

  // test 1
  res = s21_trim(str, "* /");
  ck_assert_str_eq(res, "Much Ado About Nothing");
  free(res);

  // test 2
  res = s21_trim("hello", "hello");
  ck_assert_str_eq(res, "");
  free(res);

  // test 3
  res = s21_trim(str, "/");
  ck_assert_str_eq(res, "*** Much Ado About Nothing ***");
  free(res);

  // test 4
  res = s21_trim(str, "* /Mg");
  ck_assert_str_eq(res, "uch Ado About Nothin");
  free(res);
}
END_TEST

START_TEST(s21_insert_tests) {
  char *fin;

  fin = s21_insert("QWERTY", " ", 0);
  ck_assert_str_eq(fin, " QWERTY");
  free(fin);

  fin = s21_insert("123456789", " ", 9);
  ck_assert_str_eq(fin, "123456789 ");
  free(fin);

  fin = s21_insert("ALHA", "LOHHHh", 2);
  ck_assert_str_eq(fin, "ALLOHHHhHA");
  free(fin);

  fin = s21_insert(NULL, "", 2);
  ck_assert_ptr_eq(fin, NULL);

  fin = s21_insert("    ", NULL, 2);
  ck_assert_ptr_eq(fin, NULL);

  fin = s21_insert("abc", " ", 4);
  ck_assert_ptr_eq(fin, NULL);
}
END_TEST

Suite *s21_string_test(void) {
  Suite *s1 = suite_create("s21_string tests");

  TCase *s21_memchr = tcase_create("Memchr");
  suite_add_tcase(s1, s21_memchr);
  tcase_add_test(s21_memchr, s21_memchr_0);
  tcase_add_test(s21_memchr, s21_memchr_1);
  tcase_add_test(s21_memchr, s21_memchr_2);

  TCase *s21_memcmp = tcase_create("Memcmp");
  suite_add_tcase(s1, s21_memcmp);
  tcase_add_test(s21_memcmp, s21_memcmp_0);
  tcase_add_test(s21_memcmp, s21_memcmp_1);
  tcase_add_test(s21_memcmp, s21_memcmp_2);
  tcase_add_test(s21_memcmp, s21_memcmp_3);

  TCase *s21_memmove = tcase_create("Memmove");
  suite_add_tcase(s1, s21_memmove);
  tcase_add_test(s21_memmove, s21_memmove_0);
  tcase_add_test(s21_memmove, s21_memmove_1);
  tcase_add_test(s21_memmove, s21_memmove_2);

  TCase *s21_memset = tcase_create("Memset");
  suite_add_tcase(s1, s21_memset);
  tcase_add_test(s21_memset, s21_memset_0);
  tcase_add_test(s21_memset, s21_memset_1);

  TCase *s21_memcpy = tcase_create("Memcpy");
  suite_add_tcase(s1, s21_memcpy);
  tcase_add_test(s21_memcpy, s21_memcpy_0);

  TCase *s21_strncat = tcase_create("Strncat");
  suite_add_tcase(s1, s21_strncat);
  tcase_add_test(s21_strncat, s21_strncat_0);
  tcase_add_test(s21_strncat, s21_strncat_1);
  tcase_add_test(s21_strncat, s21_strncat_2);

  TCase *s21_strcat = tcase_create("Strcat");
  suite_add_tcase(s1, s21_strcat);
  tcase_add_test(s21_strcat, s21_strcat_0);
  tcase_add_test(s21_strcat, s21_strcat_1);
  tcase_add_test(s21_strcat, s21_strcat_2);

  TCase *s21_strchr = tcase_create("Strchr");
  suite_add_tcase(s1, s21_strchr);
  tcase_add_test(s21_strchr, s21_strchr_0);

  TCase *s21_strcmp = tcase_create("Strcmp");
  suite_add_tcase(s1, s21_strcmp);
  tcase_add_test(s21_strcmp, s21_strcmp_0);

  TCase *s21_strncmp = tcase_create("Strncmp");
  suite_add_tcase(s1, s21_strncmp);
  tcase_add_test(s21_strncmp, s21_strncmp_0);

  TCase *s21_strcpy = tcase_create("Strcpy");
  suite_add_tcase(s1, s21_strcpy);
  tcase_add_test(s21_strcpy, s21_strcpy_0);

  TCase *s21_strncpy = tcase_create("Strncpy");
  suite_add_tcase(s1, s21_strncpy);
  tcase_add_test(s21_strncpy, s21_strncpy_0);

  TCase *s21_strcspn = tcase_create("Strcspn");
  suite_add_tcase(s1, s21_strcspn);
  tcase_add_test(s21_strcspn, s21_strcspn_0);

  TCase *s21_strerror = tcase_create("Strerror");
  suite_add_tcase(s1, s21_strerror);
  tcase_add_test(s21_strerror, s21_strerror_0);

  TCase *s21_strpbrk = tcase_create("Strpbrk");
  suite_add_tcase(s1, s21_strpbrk);
  tcase_add_test(s21_strpbrk, s21_strpbrk_0);

  TCase *s21_strrchr = tcase_create("Strrchr");
  suite_add_tcase(s1, s21_strrchr);
  tcase_add_test(s21_strrchr, s21_strrchr_0);

  TCase *s21_strspn = tcase_create("Strspn");
  suite_add_tcase(s1, s21_strspn);
  tcase_add_test(s21_strspn, s21_strspn_0);

  TCase *s21_strstr = tcase_create("Strstr");
  suite_add_tcase(s1, s21_strstr);
  tcase_add_test(s21_strstr, s21_strstr_0);

  TCase *s21_strtok = tcase_create("Strtok");
  suite_add_tcase(s1, s21_strtok);
  tcase_add_test(s21_strtok, s21_strtok_0);
  tcase_add_test(s21_strtok, s21_strtok_1);
  tcase_add_test(s21_strtok, s21_strtok_2);
  tcase_add_test(s21_strtok, s21_strtok_3);
  tcase_add_test(s21_strtok, s21_strtok_4);
  tcase_add_test(s21_strtok, s21_strtok_5);
  tcase_add_test(s21_strtok, s21_strtok_6);
  tcase_add_test(s21_strtok, s21_strtok_7);
  tcase_add_test(s21_strtok, s21_strtok_8);
  tcase_add_test(s21_strtok, s21_strtok_9);

  TCase *s21_special = tcase_create("Special");
  suite_add_tcase(s1, s21_special);
  tcase_add_test(s21_special, s21_to_upper_tests);
  tcase_add_test(s21_special, s21_to_lower_tests);
  tcase_add_test(s21_special, s21_trim_tests);
  tcase_add_test(s21_special, s21_insert_tests);

  return s1;
}