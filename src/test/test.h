#ifndef SRC_TEST_TEST_H_
#define SRC_TEST_TEST_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

Suite *s21_string_test(void);
Suite *s21_sprintf_test(void);
Suite *s21_sscanf_test(void);

#endif  // SRC_TEST_TEST_H_