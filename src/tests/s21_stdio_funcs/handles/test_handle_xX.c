#include <check.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_xX(char *buffer, int *j, const char *spec, int spec_int,
                    Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_xX(buffer, j, spec, &spec_int, &args, flags);
  va_end(args);
}

START_TEST(test_basic_hex) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = -1};
  unsigned value = 0xABC;
  test_handle_xX(buffer, &j, "x", 0, &flags, value);
  ck_assert_str_eq(buffer, "abc");
}
END_TEST

START_TEST(test_uppercase) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = -1};
  unsigned value = 0xABC;
  test_handle_xX(buffer, &j, "X", 0, &flags, value);
  ck_assert_str_eq(buffer, "ABC");
}
END_TEST

START_TEST(test_zero) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = -1};
  unsigned value = 0;
  test_handle_xX(buffer, &j, "x", 0, &flags, value);
  ck_assert_str_eq(buffer, "0");
}
END_TEST

START_TEST(test_hash_flag) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.with_lattice = 1, .accuracy = -1};
  unsigned value = 0xABC;
  test_handle_xX(buffer, &j, "x", 0, &flags, value);
  ck_assert_str_eq(buffer, "0xabc");
}
END_TEST

START_TEST(test_hash_uppercase) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.with_lattice = 1, .accuracy = -1};
  unsigned value = 0xABC;
  test_handle_xX(buffer, &j, "X", 0, &flags, value);
  ck_assert_str_eq(buffer, "0XABC");
}
END_TEST

START_TEST(test_width) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.width = 10, .accuracy = -1};
  unsigned value = 0xABC;
  test_handle_xX(buffer, &j, "x", 0, &flags, value);
  ck_assert_str_eq(buffer, "       abc");
}
END_TEST

START_TEST(test_zero_padding) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.width = 10, .with_zeros = 1, .accuracy = -1};
  unsigned value = 0xABC;
  test_handle_xX(buffer, &j, "x", 0, &flags, value);
  ck_assert_str_eq(buffer, "0000000abc");
}
END_TEST

START_TEST(test_precision) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = 5};
  unsigned value = 0xABC;
  test_handle_xX(buffer, &j, "x", 0, &flags, value);
  ck_assert_str_eq(buffer, "00abc");
}
END_TEST

START_TEST(test_max_unsigned) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = -1};
  unsigned value = UINT_MAX;
  test_handle_xX(buffer, &j, "x", 0, &flags, value);
  char expected[20];
  sprintf(expected, "%x", UINT_MAX);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_combined_flags) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.width = 10, .accuracy = 5, .with_lattice = 1};
  unsigned value = 0xABC;
  test_handle_xX(buffer, &j, "X", 0, &flags, value);
  ck_assert_str_eq(buffer, "   0X00ABC");
}
END_TEST

Suite *handle_xX_suite(void) {
  Suite *s = suite_create("handle_xX");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_basic_hex);
  tcase_add_test(tc, test_uppercase);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_hash_flag);
  tcase_add_test(tc, test_hash_uppercase);
  tcase_add_test(tc, test_width);
  tcase_add_test(tc, test_zero_padding);
  tcase_add_test(tc, test_precision);
  tcase_add_test(tc, test_max_unsigned);
  tcase_add_test(tc, test_combined_flags);

  suite_add_tcase(s, tc);
  return s;
}