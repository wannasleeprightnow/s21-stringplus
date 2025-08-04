#include <check.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_o(char *buffer, int *j, int *i, Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_o(buffer, j, i, &args, flags);
  va_end(args);
}

START_TEST(test_basic_octal) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.accuracy = -1};
  unsigned value = 0755;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "755");
}
END_TEST

START_TEST(test_zero) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.accuracy = -1};
  unsigned value = 0;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "0");
}
END_TEST

START_TEST(test_hash_flag) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.with_lattice = 1, .accuracy = -1};
  unsigned value = 0755;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "0755");
}
END_TEST

START_TEST(test_width) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.width = 10, .accuracy = -1};
  unsigned value = 0755;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "       755");
}
END_TEST

START_TEST(test_zero_padding) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.width = 10, .with_zeros = 1, .accuracy = -1};
  unsigned value = 0755;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "0000000755");
}
END_TEST

START_TEST(test_precision) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.accuracy = 5};
  unsigned value = 0755;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "00755");
}
END_TEST

START_TEST(test_max_unsigned) {
  char buffer[30] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.accuracy = -1};
  unsigned value = UINT_MAX;
  test_handle_o(buffer, &j, &i, &flags, value);
  char expected[30];
  sprintf(expected, "%o", UINT_MAX);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_hash_with_zero) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.with_lattice = 1, .accuracy = -1};
  unsigned value = 0;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "0");
}
END_TEST

START_TEST(test_combined_flags) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.width = 10, .accuracy = 5, .with_lattice = 1};
  unsigned value = 0755;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "     00755");
}
END_TEST

START_TEST(test_precision_greater_than_width) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  Flags flags = {.width = 5, .accuracy = 10};
  unsigned value = 0755;
  test_handle_o(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "0000000755");
}
END_TEST

Suite *handle_o_suite(void) {
  Suite *s = suite_create("handle_o");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_basic_octal);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_hash_flag);
  tcase_add_test(tc, test_width);
  tcase_add_test(tc, test_zero_padding);
  tcase_add_test(tc, test_precision);
  tcase_add_test(tc, test_max_unsigned);
  tcase_add_test(tc, test_hash_with_zero);
  tcase_add_test(tc, test_combined_flags);
  tcase_add_test(tc, test_precision_greater_than_width);

  suite_add_tcase(s, tc);
  return s;
}