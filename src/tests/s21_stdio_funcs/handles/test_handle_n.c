#include <check.h>
#include <stdarg.h>
#include <stdio.h>

#include "../../../s21_string.h"
#include "../../tests.h"

void test_handle_n(int *j, int *i, ...) {
  va_list args;
  va_start(args, i);
  handle_n(j, i, &args);
  va_end(args);
}

START_TEST(test_basic_n) {
  int j = 5;
  int i = 0;
  int count = 0;
  test_handle_n(&j, &i, &count);
  ck_assert_int_eq(count, 5);
}
END_TEST

START_TEST(test_zero_count) {
  int j = 0;
  int i = 0;
  int count = 0;
  test_handle_n(&j, &i, &count);
  ck_assert_int_eq(count, 0);
}
END_TEST

START_TEST(test_large_count) {
  int j = 1000000;
  int i = 0;
  int count = 0;
  test_handle_n(&j, &i, &count);
  ck_assert_int_eq(count, 1000000);
}
END_TEST

START_TEST(test_negative_count) {
  int j = -5;
  int i = 0;
  int count = 0;
  test_handle_n(&j, &i, &count);
  ck_assert_int_eq(count, -5);
}
END_TEST

START_TEST(test_pointer_types) {
  int j = 42;
  int i = 0;
  {
    int count = 0;
    test_handle_n(&j, &i, &count);
    ck_assert_int_eq(count, 42);
  }
  {
    short count = 0;
    test_handle_n(&j, &i, &count);
    ck_assert_int_eq(count, 42);
  }
  {
    long count = 0;
    test_handle_n(&j, &i, &count);
    ck_assert_int_eq(count, 42);
  }
}
END_TEST

START_TEST(test_multiple_n) {
  int j = 0;
  int i = 0;
  int count1 = 0, count2 = 0;

  j = 10;
  test_handle_n(&j, &i, &count1);
  ck_assert_int_eq(count1, 10);

  j = 20;
  test_handle_n(&j, &i, &count2);
  ck_assert_int_eq(count2, 20);
}
END_TEST

START_TEST(test_n_with_other_specifiers) {
  char buffer[20] = {0};
  int j = 0;
  int i = 0;
  int count = 0;
  j += sprintf(buffer + j, "Hello");
  test_handle_n(&j, &i, &count);
  ck_assert_int_eq(count, 5);

  j += sprintf(buffer + j, " World");
  test_handle_n(&j, &i, &count);
  ck_assert_int_eq(count, 11);
}
END_TEST

START_TEST(test_n_with_no_output) {
  int j = 0;
  int i = 0;
  int count = -1;
  test_handle_n(&j, &i, &count);
  ck_assert_int_eq(count, 0);
}
END_TEST

START_TEST(test_n_after_formatting) {
  char buffer[30] = {0};
  int j = 0;
  int i = 0;
  int count = 0;

  j += sprintf(buffer + j, "Number: %d", 42);
  test_handle_n(&j, &i, &count);
  ck_assert_int_eq(count, 10);
}
END_TEST

START_TEST(test_n_with_different_types) {
  int j = 0;
  int i = 0;

  {
    char count = 0;
    j = 100;
    test_handle_n(&j, &i, &count);
    ck_assert_int_eq(count, 100);
  }

  {
    long long count = 0;
    j = 1000;
    test_handle_n(&j, &i, &count);
    ck_assert_int_eq(count, 1000);
  }
}
END_TEST

Suite *handle_n_suite(void) {
  Suite *s = suite_create("handle_n");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_basic_n);
  tcase_add_test(tc, test_zero_count);
  tcase_add_test(tc, test_large_count);
  tcase_add_test(tc, test_negative_count);
  tcase_add_test(tc, test_pointer_types);
  tcase_add_test(tc, test_multiple_n);
  tcase_add_test(tc, test_n_with_other_specifiers);
  tcase_add_test(tc, test_n_with_no_output);
  tcase_add_test(tc, test_n_after_formatting);
  tcase_add_test(tc, test_n_with_different_types);

  suite_add_tcase(s, tc);
  return s;
}