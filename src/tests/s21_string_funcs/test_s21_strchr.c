#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_found_in_middle) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_strchr(str, 'c'), strchr(str, 'c'));
}
END_TEST

START_TEST(test_not_found) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_strchr(str, 'x'), strchr(str, 'x'));
}
END_TEST

START_TEST(test_found_at_start) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

START_TEST(test_found_at_end) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_strchr(str, 'f'), strchr(str, 'f'));
}
END_TEST

START_TEST(test_search_null_byte) {
  char str[] = "abc";
  ck_assert_ptr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

START_TEST(test_multiple_occurrences) {
  char str[] = "abacadae";
  ck_assert_ptr_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

START_TEST(test_empty_string) {
  char str[] = "";
  ck_assert_ptr_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

START_TEST(test_search_digit) {
  char str[] = "1234567890";
  ck_assert_ptr_eq(s21_strchr(str, '5'), strchr(str, '5'));
}
END_TEST

START_TEST(test_search_first_char_is_null) {
  char str[] = "\0abc";
  ck_assert_ptr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

START_TEST(test_search_uppercase) {
  char str[] = "abcDEF";
  ck_assert_ptr_eq(s21_strchr(str, 'D'), strchr(str, 'D'));
}
END_TEST

START_TEST(test_search_lowercase_not_found) {
  char str[] = "ABCDEF";
  ck_assert_ptr_eq(s21_strchr(str, 'd'), strchr(str, 'd'));
}
END_TEST

START_TEST(test_search_space) {
  char str[] = "hello world";
  ck_assert_ptr_eq(s21_strchr(str, ' '), strchr(str, ' '));
}
END_TEST

START_TEST(test_search_special_char) {
  char str[] = "foo@bar.com";
  ck_assert_ptr_eq(s21_strchr(str, '@'), strchr(str, '@'));
}
END_TEST

START_TEST(test_search_last_char) {
  char str[] = "test!";
  ck_assert_ptr_eq(s21_strchr(str, '!'), strchr(str, '!'));
}
END_TEST

START_TEST(test_search_value_greater_than_uchar) {
  char str[] = "abc";
  ck_assert_ptr_eq(s21_strchr(str, 257), strchr(str, 257));
}
END_TEST

START_TEST(test_search_value_less_than_zero) {
  char str[] = "abc";
  ck_assert_ptr_eq(s21_strchr(str, -255), strchr(str, -255));
}
END_TEST

START_TEST(test_search_in_string_with_repeated_chars) {
  char str[] = "aaaaaa";
  ck_assert_ptr_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strchr");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_found_in_middle);
  tcase_add_test(tc_core, test_not_found);
  tcase_add_test(tc_core, test_found_at_start);
  tcase_add_test(tc_core, test_found_at_end);
  tcase_add_test(tc_core, test_search_null_byte);
  tcase_add_test(tc_core, test_multiple_occurrences);
  tcase_add_test(tc_core, test_empty_string);
  tcase_add_test(tc_core, test_search_digit);
  tcase_add_test(tc_core, test_search_first_char_is_null);
  tcase_add_test(tc_core, test_search_uppercase);
  tcase_add_test(tc_core, test_search_lowercase_not_found);
  tcase_add_test(tc_core, test_search_space);
  tcase_add_test(tc_core, test_search_special_char);
  tcase_add_test(tc_core, test_search_last_char);
  tcase_add_test(tc_core, test_search_value_greater_than_uchar);
  tcase_add_test(tc_core, test_search_value_less_than_zero);
  tcase_add_test(tc_core, test_search_in_string_with_repeated_chars);

  suite_add_tcase(s, tc_core);
  return s;
}