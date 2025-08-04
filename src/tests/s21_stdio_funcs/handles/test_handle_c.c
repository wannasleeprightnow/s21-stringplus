#include <check.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_c(char *buffer, int *j, int *i, Flags *flags, ...) {
  va_list args;
  va_start(args, flags);
  handle_c(buffer, j, i, &args, flags);
  va_end(args);
}

START_TEST(test_basic_char) {
  char buffer[10] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_c(buffer, &j, &i, &flags, 'A');
  ck_assert_int_eq(buffer[0], 'A');
}
END_TEST

START_TEST(test_null_char) {
  char buffer[10] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_c(buffer, &j, &i, &flags, '\0');
  ck_assert_int_eq(buffer[0], '\0');
}
END_TEST

START_TEST(test_width_padding) {
  char buffer[10] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 5, .accuracy = -1};
  test_handle_c(buffer, &j, &i, &flags, 'X');
  ck_assert_str_eq(buffer, "    X");
}
END_TEST

START_TEST(test_left_align) {
  char buffer[10] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 5, .sign = '-', .accuracy = -1};
  test_handle_c(buffer, &j, &i, &flags, 'X');
  ck_assert_str_eq(buffer, "X    ");
}
END_TEST

START_TEST(test_zero_padding) {
  char buffer[10] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 5, .with_zeros = 1, .accuracy = -1};
  test_handle_c(buffer, &j, &i, &flags, 'X');
  ck_assert_str_eq(buffer, "    X");
}
END_TEST

START_TEST(test_non_ascii) {
  char buffer[10] = {0};
  int j = 0, i = 0;
  Flags flags = {.accuracy = -1};
  test_handle_c(buffer, &j, &i, &flags, 0x80);
  ck_assert_int_eq((unsigned char)buffer[0], 0x80);
}
END_TEST

START_TEST(test_max_width) {
  char buffer[20] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 10, .accuracy = -1};
  test_handle_c(buffer, &j, &i, &flags, 'X');
  ck_assert_str_eq(buffer, "         X");
}
END_TEST

START_TEST(test_combined_flags) {
  char buffer[10] = {0};
  int j = 0, i = 0;
  Flags flags = {.width = 5, .sign = '-', .with_zeros = 1, .accuracy = -1};
  test_handle_c(buffer, &j, &i, &flags, 'X');
  ck_assert_str_eq(buffer, "X    ");
}
END_TEST

Suite *handle_c_suite(void) {
  Suite *s = suite_create("handle_c");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, test_basic_char);
  tcase_add_test(tc, test_null_char);
  tcase_add_test(tc, test_width_padding);
  tcase_add_test(tc, test_left_align);
  tcase_add_test(tc, test_zero_padding);
  tcase_add_test(tc, test_non_ascii);
  tcase_add_test(tc, test_max_width);
  tcase_add_test(tc, test_combined_flags);
  suite_add_tcase(s, tc);
  return s;
}