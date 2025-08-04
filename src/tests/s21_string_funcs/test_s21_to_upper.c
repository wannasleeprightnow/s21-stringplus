#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_s21_to_upper_simple) {
  char *res = (char *)s21_to_upper("hello");
  ck_assert_str_eq(res, "HELLO");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_mixed) {
  char *res = (char *)s21_to_upper("HeLLo WoRLd!");
  ck_assert_str_eq(res, "HELLO WORLD!");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_no_lower) {
  char *res = (char *)s21_to_upper("ALREADY UPPER");
  ck_assert_str_eq(res, "ALREADY UPPER");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_empty) {
  char *res = (char *)s21_to_upper("");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_numbers_and_symbols) {
  char *res = (char *)s21_to_upper("1234!@#abcXYZ");
  ck_assert_str_eq(res, "1234!@#ABCXYZ");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_only_lower) {
  char *res = (char *)s21_to_upper("lowercase");
  ck_assert_str_eq(res, "LOWERCASE");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_only_upper) {
  char *res = (char *)s21_to_upper("UPPERCASE");
  ck_assert_str_eq(res, "UPPERCASE");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_one_char_lower) {
  char *res = (char *)s21_to_upper("a");
  ck_assert_str_eq(res, "A");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_one_char_upper) {
  char *res = (char *)s21_to_upper("Z");
  ck_assert_str_eq(res, "Z");
  free(res);
}
END_TEST

START_TEST(test_s21_to_upper_non_ascii) {
  char *res = (char *)s21_to_upper("Привет, мир!");
  ck_assert_str_eq(res, "Привет, мир!");
  free(res);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_s21_to_upper_simple);
  tcase_add_test(tc, test_s21_to_upper_mixed);
  tcase_add_test(tc, test_s21_to_upper_no_lower);
  tcase_add_test(tc, test_s21_to_upper_empty);
  tcase_add_test(tc, test_s21_to_upper_numbers_and_symbols);
  tcase_add_test(tc, test_s21_to_upper_only_lower);
  tcase_add_test(tc, test_s21_to_upper_only_upper);
  tcase_add_test(tc, test_s21_to_upper_one_char_lower);
  tcase_add_test(tc, test_s21_to_upper_one_char_upper);
  tcase_add_test(tc, test_s21_to_upper_non_ascii);

  suite_add_tcase(s, tc);
  return s;
}