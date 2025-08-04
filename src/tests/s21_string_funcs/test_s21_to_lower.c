#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_s21_to_lower_simple) {
  char *res = (char *)s21_to_lower("HELLO");
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_mixed) {
  char *res = (char *)s21_to_lower("HeLLo WoRLd!");
  ck_assert_str_eq(res, "hello world!");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_no_upper) {
  char *res = (char *)s21_to_lower("already lower");
  ck_assert_str_eq(res, "already lower");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_empty) {
  char *res = (char *)s21_to_lower("");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_numbers_and_symbols) {
  char *res = (char *)s21_to_lower("1234!@#ABCxyz");
  ck_assert_str_eq(res, "1234!@#abcxyz");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_only_upper) {
  char *res = (char *)s21_to_lower("UPPERCASE");
  ck_assert_str_eq(res, "uppercase");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_only_lower) {
  char *res = (char *)s21_to_lower("lowercase");
  ck_assert_str_eq(res, "lowercase");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_one_char_upper) {
  char *res = (char *)s21_to_lower("A");
  ck_assert_str_eq(res, "a");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_one_char_lower) {
  char *res = (char *)s21_to_lower("z");
  ck_assert_str_eq(res, "z");
  free(res);
}
END_TEST

START_TEST(test_s21_to_lower_non_ascii) {
  char *res = (char *)s21_to_lower("Привет, МИР!");
  ck_assert_str_eq(res, "Привет, МИР!");
  free(res);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_s21_to_lower_simple);
  tcase_add_test(tc, test_s21_to_lower_mixed);
  tcase_add_test(tc, test_s21_to_lower_no_upper);
  tcase_add_test(tc, test_s21_to_lower_empty);
  tcase_add_test(tc, test_s21_to_lower_numbers_and_symbols);
  tcase_add_test(tc, test_s21_to_lower_only_upper);
  tcase_add_test(tc, test_s21_to_lower_only_lower);
  tcase_add_test(tc, test_s21_to_lower_one_char_upper);
  tcase_add_test(tc, test_s21_to_lower_one_char_lower);
  tcase_add_test(tc, test_s21_to_lower_non_ascii);

  suite_add_tcase(s, tc);
  return s;
}