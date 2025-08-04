#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../../../s21_string.h"
#include "../../tests.h"

START_TEST(test_single_percent) {
  char mybuf[10] = {0};
  char stdbuf[10] = {0};
  int j = 0;
  handle_percent(mybuf, &j);
  sprintf(stdbuf, "%%");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_percent_with_text) {
  char mybuf[20] = {0};
  char stdbuf[20] = {0};
  int j = 0;
  j += sprintf(mybuf + j, "abc");
  handle_percent(mybuf, &j);
  j += sprintf(mybuf + j, "def");
  sprintf(stdbuf, "abc%%def");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_double_percent) {
  char mybuf[10] = {0};
  char stdbuf[10] = {0};
  int j = 0;
  handle_percent(mybuf, &j);
  handle_percent(mybuf, &j);
  sprintf(stdbuf, "%%%%");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_percent_at_start) {
  char mybuf[10] = {0};
  char stdbuf[10] = {0};
  int j = 0;
  handle_percent(mybuf, &j);
  j += sprintf(mybuf + j, "start");
  sprintf(stdbuf, "%%start");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_percent_at_end) {
  char mybuf[10] = {0};
  char stdbuf[10] = {0};
  int j = 0;
  j += sprintf(mybuf + j, "end");
  handle_percent(mybuf, &j);
  sprintf(stdbuf, "end%%");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_percent_in_middle) {
  char mybuf[20] = {0};
  char stdbuf[20] = {0};
  int j = 0;
  j += sprintf(mybuf + j, "foo");
  handle_percent(mybuf, &j);
  j += sprintf(mybuf + j, "bar");
  handle_percent(mybuf, &j);
  sprintf(stdbuf, "foo%%bar%%");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_percent_with_numbers) {
  char mybuf[20] = {0};
  char stdbuf[20] = {0};
  int j = 0;
  j += sprintf(mybuf + j, "123");
  handle_percent(mybuf, &j);
  j += sprintf(mybuf + j, "456");
  sprintf(stdbuf, "123%%456");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_percent_only) {
  char mybuf[2] = {0};
  char stdbuf[2] = {0};
  int j = 0;
  handle_percent(mybuf, &j);
  sprintf(stdbuf, "%%");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_percent_with_spaces) {
  char mybuf[20] = {0};
  char stdbuf[20] = {0};
  int j = 0;
  j += sprintf(mybuf + j, " a ");
  handle_percent(mybuf, &j);
  j += sprintf(mybuf + j, " b ");
  sprintf(stdbuf, " a %% b ");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

START_TEST(test_percent_with_empty_string) {
  char mybuf[2] = {0};
  char stdbuf[2] = {0};
  int j = 0;
  handle_percent(mybuf, &j);
  sprintf(stdbuf, "%%");
  ck_assert_str_eq(mybuf, stdbuf);
  ck_assert_int_eq(j, strlen(stdbuf));
}
END_TEST

Suite *handle_percent_suite(void) {
  Suite *s = suite_create("handle_percent");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_single_percent);
  tcase_add_test(tc, test_percent_with_text);
  tcase_add_test(tc, test_double_percent);
  tcase_add_test(tc, test_percent_at_start);
  tcase_add_test(tc, test_percent_at_end);
  tcase_add_test(tc, test_percent_in_middle);
  tcase_add_test(tc, test_percent_with_numbers);
  tcase_add_test(tc, test_percent_only);
  tcase_add_test(tc, test_percent_with_spaces);
  tcase_add_test(tc, test_percent_with_empty_string);

  suite_add_tcase(s, tc);
  return s;
}