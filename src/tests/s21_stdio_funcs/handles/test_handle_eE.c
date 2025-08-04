#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_eE(char *buffer, int *j, const char *spec, int *i,
                    Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_eE(buffer, j, spec, i, &args, flags);
  va_end(args);
}

START_TEST(test_basic_e) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 123.456;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_uppercase_E) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 123.456;
  test_handle_eE(buffer, &j, "E", &i, &flags, val);
  sprintf(expected, "%E", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_negative_number) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = -123.456;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 0.0;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 3};
  double val = 123.456;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%.3e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_large_number) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 1.23456e20;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_small_number) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = 1.23456e-20;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_infinity) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = INFINITY;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_nan) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  double val = NAN;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_combined_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 20, .accuracy = 3, .sign = '+'};
  double val = 123.456;
  test_handle_eE(buffer, &j, "E", &i, &flags, val);
  sprintf(expected, "%+20.3E", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_accuracy_zero_positive) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0};
  double val = 123.456;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%.0e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_accuracy_zero_negative) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0};
  double val = -123.456;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%.0e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_accuracy_zero_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0};
  double val = 0.0;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%.0e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_accuracy_zero_large) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0};
  double val = 1.23456e20;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%.0e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_accuracy_zero_small) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0};
  double val = 1.23456e-20;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%.0e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_accuracy_zero_with_lattice) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0, .with_lattice = 1};
  double val = 123.456;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%#.0e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_accuracy_zero_with_lattice_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 0, .with_lattice = 1};
  double val = 0.0;
  test_handle_eE(buffer, &j, "e", &i, &flags, val);
  sprintf(expected, "%#.0e", val);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

Suite *handle_eE_suite(void) {
  Suite *s = suite_create("handle_eE");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_basic_e);
  tcase_add_test(tc, test_uppercase_E);
  tcase_add_test(tc, test_negative_number);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_precision);
  tcase_add_test(tc, test_large_number);
  tcase_add_test(tc, test_small_number);
  tcase_add_test(tc, test_infinity);
  tcase_add_test(tc, test_nan);
  tcase_add_test(tc, test_combined_flags);
  tcase_add_test(tc, test_accuracy_zero_positive);
  tcase_add_test(tc, test_accuracy_zero_negative);
  tcase_add_test(tc, test_accuracy_zero_zero);
  tcase_add_test(tc, test_accuracy_zero_large);
  tcase_add_test(tc, test_accuracy_zero_small);
  tcase_add_test(tc, test_accuracy_zero_with_lattice);
  tcase_add_test(tc, test_accuracy_zero_with_lattice_zero);

  suite_add_tcase(s, tc);
  return s;
}