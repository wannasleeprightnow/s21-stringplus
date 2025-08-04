#include <check.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_p(char *buffer, int *j, int *i, Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_p(buffer, j, i, &args, flags);
  va_end(args);
}

START_TEST(test_null_pointer) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  void *value = NULL;
  test_handle_p(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "(nil)");
}
END_TEST

START_TEST(test_valid_pointer) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  int x = 42;
  void *value = &x;
  test_handle_p(buffer, &j, &i, &flags, value);
  char expected[20];
  sprintf(expected, "%p", &x);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_zero_address) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  void *value = (void *)0x0;
  test_handle_p(buffer, &j, &i, &flags, value);
  ck_assert_str_eq(buffer, "(nil)");
}
END_TEST

START_TEST(test_width) {
  char buffer[30] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 20, .accuracy = -1};
  int x = 42;
  void *value = &x;
  test_handle_p(buffer, &j, &i, &flags, value);
  char expected[30];
  sprintf(expected, "%20p", &x);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_zero_padding_fn) {
  char buffer[30] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 20, .accuracy = -1};
  int x = 42;
  void *value = &x;
  test_handle_p(buffer, &j, &i, &flags, value);
  char expected[30];
  sprintf(expected, "%20p", &x);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_left_align) {
  char buffer[30] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 20, .sign = '-', .accuracy = -1};
  int x = 42;
  void *value = &x;
  test_handle_p(buffer, &j, &i, &flags, value);
  char expected[30];
  sprintf(expected, "%-20p", &x);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_large_address) {
  char buffer[30] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  void *value = (void *)0x7FFFFFFFFFFFFFFF;
  test_handle_p(buffer, &j, &i, &flags, value);
  char expected[30];
  sprintf(expected, "%p", (void *)0x7FFFFFFFFFFFFFFF);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_combined_flags_fn) {
  char buffer[30] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 20, .with_zeros = 1, .sign = '-', .accuracy = -1};
  int x = 42;
  void *value = &x;
  test_handle_p(buffer, &j, &i, &flags, value);
  char expected[30];
  sprintf(expected, "%-20p", &x);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_stack_address) {
  char buffer[30] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  int stack_var;
  void *value = &stack_var;
  test_handle_p(buffer, &j, &i, &flags, value);
  char expected[30];
  sprintf(expected, "%p", &stack_var);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_heap_address) {
  char buffer[30] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  void *value = malloc(1);
  test_handle_p(buffer, &j, &i, &flags, value);
  char expected[30];
  sprintf(expected, "%p", value);
  ck_assert_str_eq(buffer, expected);
  free(value);
}
END_TEST

Suite *handle_p_suite(void) {
  Suite *s = suite_create("handle_p");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_null_pointer);
  tcase_add_test(tc, test_valid_pointer);
  tcase_add_test(tc, test_zero_address);
  tcase_add_test(tc, test_width);
  tcase_add_test(tc, test_zero_padding_fn);
  tcase_add_test(tc, test_left_align);
  tcase_add_test(tc, test_large_address);
  tcase_add_test(tc, test_combined_flags_fn);
  tcase_add_test(tc, test_stack_address);
  tcase_add_test(tc, test_heap_address);

  suite_add_tcase(s, tc);
  return s;
}