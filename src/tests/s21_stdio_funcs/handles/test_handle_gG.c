#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_gG(char *buffer, int *j, const char *spec, int *i,
                    Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_gG(buffer, j, spec, i, &args, flags);
  va_end(args);
}

START_TEST(test_basic_g) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 123.456;
  test_handle_gG(buffer, &j, "g", &i, &flags, val);
  sprintf(expected, "%g", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_uppercase_G) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 123.456;
  test_handle_gG(buffer, &j, "G", &i, &flags, val);
  sprintf(expected, "%G", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_large_number_g) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 123456789.0;
  test_handle_gG(buffer, &j, "g", &i, &flags, val);
  sprintf(expected, "%g", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_small_number_g) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 0.000000123;
  test_handle_gG(buffer, &j, "g", &i, &flags, val);
  sprintf(expected, "%g", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 3};
  double val = 123.456;
  test_handle_gG(buffer, &j, "g", &i, &flags, val);
  sprintf(expected, "%.3g", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_zero_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0};
  double val = 123.456;
  test_handle_gG(buffer, &j, "g", &i, &flags, val);
  sprintf(expected, "%.0g", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_trailing_zeros) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 6};
  double val = 123.0;
  test_handle_gG(buffer, &j, "g", &i, &flags, val);
  sprintf(expected, "%.6g", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_infinity) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = INFINITY;
  test_handle_gG(buffer, &j, "g", &i, &flags, val);
  sprintf(expected, "%g", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_nan) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = NAN;
  test_handle_gG(buffer, &j, "g", &i, &flags, val);
  sprintf(expected, "%g", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_combined_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 15, .accuracy = 3, .sign = '+', .with_space = 0};
  double val = 123.456;
  test_handle_gG(buffer, &j, "G", &i, &flags, val);
  sprintf(expected, "%+15.3G", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

Suite *handle_gG_suite(void) {
  Suite *s = suite_create("handle_gG");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_basic_g);
  tcase_add_test(tc, test_uppercase_G);
  tcase_add_test(tc, test_large_number_g);
  tcase_add_test(tc, test_small_number_g);
  tcase_add_test(tc, test_precision);
  tcase_add_test(tc, test_zero_precision);
  tcase_add_test(tc, test_trailing_zeros);
  tcase_add_test(tc, test_infinity);
  tcase_add_test(tc, test_nan);
  tcase_add_test(tc, test_combined_flags);

  suite_add_tcase(s, tc);
  return s;
}
