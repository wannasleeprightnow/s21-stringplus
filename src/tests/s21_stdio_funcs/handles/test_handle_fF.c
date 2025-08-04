#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_fF(char *buffer, int *j, int *i, Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_fF(buffer, j, i, &args, flags);
  va_end(args);
}

START_TEST(test_basic_float) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_fF(buffer, &j, &i, &flags, 123.456);
  ck_assert_str_eq(buffer, "123.456000");
}
END_TEST

START_TEST(test_negative_float) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_fF(buffer, &j, &i, &flags, -123.456);
  ck_assert_str_eq(buffer, "-123.456000");
}
END_TEST

START_TEST(test_zero) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_fF(buffer, &j, &i, &flags, 0.0);
  ck_assert_str_eq(buffer, "0.000000");
}
END_TEST

START_TEST(test_precision) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 2};
  test_handle_fF(buffer, &j, &i, &flags, 123.456);
  ck_assert_str_eq(buffer, "123.46");
}
END_TEST

START_TEST(test_zero_precision) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0};
  test_handle_fF(buffer, &j, &i, &flags, 123.456);
  ck_assert_str_eq(buffer, "123");
}
END_TEST

START_TEST(test_large_number) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_fF(buffer, &j, &i, &flags, 123456789.123456789);
  ck_assert_str_eq(buffer, "123456789.123457");
}
END_TEST

START_TEST(test_small_number) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_fF(buffer, &j, &i, &flags, 0.000000123);
  ck_assert_str_eq(buffer, "0.000000");
}
END_TEST

START_TEST(test_infinity) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_fF(buffer, &j, &i, &flags, INFINITY);
  ck_assert_str_eq(buffer, "inf");
}
END_TEST

START_TEST(test_nan) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_fF(buffer, &j, &i, &flags, NAN);
  ck_assert_str_eq(buffer, "nan");
}
END_TEST

START_TEST(test_combined_flags) {
  char buffer[50] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 15, .accuracy = 3, .sign = '+', .with_space = 1};
  test_handle_fF(buffer, &j, &i, &flags, 123.456);
  ck_assert_str_eq(buffer, "       +123.456");
}
END_TEST

Suite *handle_fF_suite(void) {
  Suite *s = suite_create("handle_fF");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_basic_float);
  tcase_add_test(tc, test_negative_float);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_precision);
  tcase_add_test(tc, test_zero_precision);
  tcase_add_test(tc, test_large_number);
  tcase_add_test(tc, test_small_number);
  tcase_add_test(tc, test_infinity);
  tcase_add_test(tc, test_nan);
  tcase_add_test(tc, test_combined_flags);

  suite_add_tcase(s, tc);
  return s;
}