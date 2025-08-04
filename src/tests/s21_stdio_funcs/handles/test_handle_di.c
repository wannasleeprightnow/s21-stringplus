#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_di(char *buffer, int *j, int *i, Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_di(buffer, j, i, &args, flags);
  va_end(args);
}

START_TEST(test_positive_int) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, 12345);
  ck_assert_str_eq(buffer, "12345");
}
END_TEST

START_TEST(test_negative_int) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, -12345);
  ck_assert_str_eq(buffer, "-12345");
}
END_TEST

START_TEST(test_zero) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, 0);
  ck_assert_str_eq(buffer, "0");
}
END_TEST

START_TEST(test_int_max) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, INT_MAX);
  char expected[20];
  sprintf(expected, "%d", INT_MAX);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_int_min) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, INT_MIN);
  char expected[20];
  sprintf(expected, "%d", INT_MIN);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_width) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 10, .accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, 123);
  ck_assert_str_eq(buffer, "       123");
}
END_TEST

START_TEST(test_zero_padding) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 10, .with_zeros = 1, .accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, 123);
  ck_assert_str_eq(buffer, "0000000123");
}
END_TEST

START_TEST(test_precision) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = 5};
  test_handle_di(buffer, &j, &i, &flags, 123);
  ck_assert_str_eq(buffer, "00123");
}
END_TEST

START_TEST(test_plus_flag) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.sign = '+', .accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, 123);
  ck_assert_str_eq(buffer, "+123");
}
END_TEST

START_TEST(test_space_flag) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.with_space = 1, .accuracy = -1};
  test_handle_di(buffer, &j, &i, &flags, 123);
  ck_assert_str_eq(buffer, " 123");
}
END_TEST

Suite *handle_di_suite(void) {
  Suite *s = suite_create("handle_di");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_positive_int);
  tcase_add_test(tc, test_negative_int);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_int_max);
  tcase_add_test(tc, test_int_min);
  tcase_add_test(tc, test_width);
  tcase_add_test(tc, test_zero_padding);
  tcase_add_test(tc, test_precision);
  tcase_add_test(tc, test_plus_flag);
  tcase_add_test(tc, test_space_flag);

  suite_add_tcase(s, tc);
  return s;
}
