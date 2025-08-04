#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_equal_strings) {
  char *a = "abcdef";
  char *b = "abcdef";
  ck_assert_int_eq(s21_strncmp(a, b, 6), strncmp(a, b, 6));
}
END_TEST

START_TEST(test_first_less) {
  char *a = "abcdee";
  char *b = "abcdef";
  ck_assert_int_eq(s21_strncmp(a, b, 6), strncmp(a, b, 6));
}
END_TEST

START_TEST(test_first_greater) {
  char *a = "abcdeg";
  char *b = "abcdef";
  ck_assert_int_eq(s21_strncmp(a, b, 6), strncmp(a, b, 6));
}
END_TEST

START_TEST(test_zero_length) {
  char *a = "abc";
  char *b = "def";
  ck_assert_int_eq(s21_strncmp(a, b, 0), strncmp(a, b, 0));
}
END_TEST

START_TEST(test_partial_compare) {
  char *a = "abcxyz";
  char *b = "abcuvw";
  ck_assert_int_eq(s21_strncmp(a, b, 3), strncmp(a, b, 3));
}
END_TEST

START_TEST(test_compare_with_null_bytes) {
  char a[] = "abc\0def";
  char b[] = "abc\0xyz";
  ck_assert_int_eq(s21_strncmp(a, b, 7), strncmp(a, b, 7));
}
END_TEST

START_TEST(test_empty_strings) {
  char *a = "";
  char *b = "";
  ck_assert_int_eq(s21_strncmp(a, b, 1), strncmp(a, b, 1));
}
END_TEST

START_TEST(test_n_greater_than_length) {
  char *a = "abc";
  char *b = "abc";
  ck_assert_int_eq(s21_strncmp(a, b, 10), strncmp(a, b, 10));
}
END_TEST

START_TEST(test_one_byte_difference) {
  char *a = "a";
  char *b = "b";
  ck_assert_int_eq(s21_strncmp(a, b, 1), strncmp(a, b, 1));
}
END_TEST

START_TEST(test_compare_with_empty) {
  char *a = "";
  char *b = "abc";
  ck_assert_int_eq(s21_strncmp(a, b, 3), strncmp(a, b, 3));
}
END_TEST

START_TEST(test_compare_first_char_diff) {
  char *a = "xbcdef";
  char *b = "abcdef";
  ck_assert_int_eq(s21_strncmp(a, b, 6), strncmp(a, b, 6));
}
END_TEST

START_TEST(test_compare_last_char_diff) {
  char *a = "abcdea";
  char *b = "abcdeb";
  ck_assert_int_eq(s21_strncmp(a, b, 6), strncmp(a, b, 6));
}
END_TEST

START_TEST(test_compare_with_space) {
  char *a = "abc def";
  char *b = "abc!def";
  ck_assert_int_eq(s21_strncmp(a, b, 7), strncmp(a, b, 7));
}
END_TEST

START_TEST(test_compare_with_special_chars) {
  char *a = "abc$%^";
  char *b = "abc$%&";
  ck_assert_int_eq(s21_strncmp(a, b, 6), strncmp(a, b, 6));
}
END_TEST

START_TEST(test_compare_with_numbers) {
  char *a = "abc123";
  char *b = "abc124";
  ck_assert_int_eq(s21_strncmp(a, b, 6), strncmp(a, b, 6));
}
END_TEST

START_TEST(test_compare_with_tab_and_newline) {
  char *a = "abc\tdef";
  char *b = "abc\ndef";
  ck_assert_int_eq(s21_strncmp(a, b, 7), strncmp(a, b, 7));
}
END_TEST

START_TEST(test_compare_unicode) {
  char *a = "абвгд";
  char *b = "абвгз";
  ck_assert_int_eq(s21_strncmp(a, b, 10), strncmp(a, b, 10));
}
END_TEST

START_TEST(test_compare_partial_unicode) {
  char *a = "абв";
  char *b = "абг";
  ck_assert_int_eq(s21_strncmp(a, b, 4), strncmp(a, b, 4));
}
END_TEST

START_TEST(test_compare_with_null_in_middle) {
  char a[] = "abc\0def";
  char b[] = "abc\0deg";
  ck_assert_int_eq(s21_strncmp(a, b, 7), strncmp(a, b, 7));
}
END_TEST

START_TEST(test_compare_empty_and_nonempty) {
  char *a = "";
  char *b = "a";
  ck_assert_int_eq(s21_strncmp(a, b, 1), strncmp(a, b, 1));
}
END_TEST

START_TEST(test_compare_both_empty_n_zero) {
  char *a = "";
  char *b = "";
  ck_assert_int_eq(s21_strncmp(a, b, 0), strncmp(a, b, 0));
}
END_TEST

START_TEST(test_compare_n_is_one) {
  char *a = "abc";
  char *b = "abd";
  ck_assert_int_eq(s21_strncmp(a, b, 1), strncmp(a, b, 1));
}
END_TEST

START_TEST(test_compare_n_is_two) {
  char *a = "abc";
  char *b = "abd";
  ck_assert_int_eq(s21_strncmp(a, b, 2), strncmp(a, b, 2));
}
END_TEST

START_TEST(test_compare_n_is_three) {
  char *a = "abc";
  char *b = "abd";
  ck_assert_int_eq(s21_strncmp(a, b, 3), strncmp(a, b, 3));
}
END_TEST

START_TEST(test_compare_n_is_four) {
  char *a = "abc";
  char *b = "abd";
  ck_assert_int_eq(s21_strncmp(a, b, 4), strncmp(a, b, 4));
}
END_TEST

START_TEST(test_compare_with_non_ascii) {
  char a[] = {0xC0, 0xC1, 0xC2, 0};
  char b[] = {0xC0, 0xC1, 0xC3, 0};
  ck_assert_int_eq(s21_strncmp(a, b, 4), strncmp(a, b, 4));
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncmp");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_equal_strings);
  tcase_add_test(tc_core, test_first_less);
  tcase_add_test(tc_core, test_first_greater);
  tcase_add_test(tc_core, test_zero_length);
  tcase_add_test(tc_core, test_partial_compare);
  tcase_add_test(tc_core, test_compare_with_null_bytes);
  tcase_add_test(tc_core, test_empty_strings);
  tcase_add_test(tc_core, test_n_greater_than_length);
  tcase_add_test(tc_core, test_one_byte_difference);
  tcase_add_test(tc_core, test_compare_with_empty);

  tcase_add_test(tc_core, test_compare_first_char_diff);
  tcase_add_test(tc_core, test_compare_last_char_diff);
  tcase_add_test(tc_core, test_compare_with_space);
  tcase_add_test(tc_core, test_compare_with_special_chars);
  tcase_add_test(tc_core, test_compare_with_numbers);
  tcase_add_test(tc_core, test_compare_with_tab_and_newline);
  tcase_add_test(tc_core, test_compare_unicode);
  tcase_add_test(tc_core, test_compare_partial_unicode);
  tcase_add_test(tc_core, test_compare_with_null_in_middle);
  tcase_add_test(tc_core, test_compare_empty_and_nonempty);
  tcase_add_test(tc_core, test_compare_both_empty_n_zero);
  tcase_add_test(tc_core, test_compare_n_is_one);
  tcase_add_test(tc_core, test_compare_n_is_two);
  tcase_add_test(tc_core, test_compare_n_is_three);
  tcase_add_test(tc_core, test_compare_n_is_four);
  tcase_add_test(tc_core, test_compare_with_non_ascii);

  suite_add_tcase(s, tc_core);
  return s;
}