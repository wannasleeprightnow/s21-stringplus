#include <check.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_s(char *buffer, int *j, int spec, Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_s(buffer, j, &spec, &args, flags);
  va_end(args);
}

START_TEST(test_basic_string) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = -1};
  char *value = "Hello";
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "Hello");
}
END_TEST

START_TEST(test_null_string) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = -1};
  char *value = NULL;
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "(null)");
}
END_TEST

START_TEST(test_empty_string) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = -1};
  char *value = "";
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "");
}
END_TEST

START_TEST(test_width) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.width = 10, .accuracy = -1};
  char *value = "Hi";
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "        Hi");
}
END_TEST

START_TEST(test_left_align) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.width = 10, .sign = '-', .accuracy = -1};
  char *value = "Hi";
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "Hi        ");
}
END_TEST

START_TEST(test_precision) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = 3};
  char *value = "Hello";
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "Hel");
}
END_TEST

START_TEST(test_zero_precision) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.accuracy = 0};
  char *value = "Hello";
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "");
}
END_TEST

START_TEST(test_combined_flags) {
  char buffer[20] = {0};
  int j = 0;
  Flags flags = {.width = 10, .accuracy = 3, .sign = '-'};
  char *value = "Hello";
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "Hel       ");
}
END_TEST

START_TEST(test_long_string) {
  char buffer[50] = {0};
  int j = 0;
  Flags flags = {.accuracy = -1};
  char *value = "This is a very long string for testing";
  test_handle_s(buffer, &j, 0, &flags, value);
  ck_assert_str_eq(buffer, "This is a very long string for testing");
}
END_TEST

Suite *handle_s_suite(void) {
  Suite *s = suite_create("handle_s");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_basic_string);
  tcase_add_test(tc, test_null_string);
  tcase_add_test(tc, test_empty_string);
  tcase_add_test(tc, test_width);
  tcase_add_test(tc, test_left_align);
  tcase_add_test(tc, test_precision);
  tcase_add_test(tc, test_zero_precision);
  tcase_add_test(tc, test_combined_flags);
  tcase_add_test(tc, test_long_string);

  suite_add_tcase(s, tc);
  return s;
}