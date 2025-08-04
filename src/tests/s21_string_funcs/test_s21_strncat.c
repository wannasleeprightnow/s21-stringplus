#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_simple_concat) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "world!";
  s21_strncat(dest1, src, 6);
  strncat(dest2, src, 6);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_n_greater_than_src) {
  char dest1[20] = "foo";
  char dest2[20] = "foo";
  char src[] = "bar";
  s21_strncat(dest1, src, 10);
  strncat(dest2, src, 10);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_n_zero) {
  char dest1[20] = "abc";
  char dest2[20] = "abc";
  char src[] = "def";
  s21_strncat(dest1, src, 0);
  strncat(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_empty_src) {
  char dest1[20] = "test";
  char dest2[20] = "test";
  char src[] = "";
  s21_strncat(dest1, src, 5);
  strncat(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_empty_dest) {
  char dest1[20] = "";
  char dest2[20] = "";
  char src[] = "abc";
  s21_strncat(dest1, src, 2);
  strncat(dest2, src, 2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_with_null_in_src) {
  char dest1[20] = "start";
  char dest2[20] = "start";
  char src[] = "abc\0def";
  s21_strncat(dest1, src, 7);
  strncat(dest2, src, 7);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_n_is_one) {
  char dest1[20] = "foo";
  char dest2[20] = "foo";
  char src[] = "bar";
  s21_strncat(dest1, src, 1);
  strncat(dest2, src, 1);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_long_src) {
  char dest1[50] = "prefix";
  char dest2[50] = "prefix";
  char src[] = "abcdefghijklmnopqrstuvwxyz";
  s21_strncat(dest1, src, 26);
  strncat(dest2, src, 26);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_return_value) {
  char dest[20] = "abc";
  char *ret = s21_strncat(dest, "def", 2);
  ck_assert_ptr_eq(ret, dest);
}
END_TEST

START_TEST(test_concat_to_empty_with_n_zero) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[] = "abc";
  s21_strncat(dest1, src, 0);
  strncat(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_empty_src_and_dest) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[] = "";
  s21_strncat(dest1, src, 5);
  strncat(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_n_is_length_of_dest) {
  char dest1[20] = "abc";
  char dest2[20] = "abc";
  char src[] = "def";
  s21_strncat(dest1, src, strlen(dest1));
  strncat(dest2, src, strlen(dest2));
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_with_special_chars) {
  char dest1[30] = "foo";
  char dest2[30] = "foo";
  char src[] = "!@#\n\t";
  s21_strncat(dest1, src, 5);
  strncat(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_with_space) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char src[] = " world";
  s21_strncat(dest1, src, 6);
  strncat(dest2, src, 6);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_unicode) {
  char dest1[40] = "test";
  char dest2[40] = "test";
  char src[] = "абв";
  s21_strncat(dest1, src, 6);
  strncat(dest2, src, 6);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_partial_unicode) {
  char dest1[40] = "test";
  char dest2[40] = "test";
  char src[] = "абв";
  s21_strncat(dest1, src, 2);
  strncat(dest2, src, 2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_n_is_zero_with_nonempty_dest) {
  char dest1[20] = "abc";
  char dest2[20] = "abc";
  char src[] = "def";
  s21_strncat(dest1, src, 0);
  strncat(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_n_is_zero_with_nonempty_src) {
  char dest1[20] = "";
  char dest2[20] = "";
  char src[] = "def";
  s21_strncat(dest1, src, 0);
  strncat(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_n_is_zero_with_both_empty) {
  char dest1[20] = "";
  char dest2[20] = "";
  char src[] = "";
  s21_strncat(dest1, src, 0);
  strncat(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_large_n) {
  char dest1[100] = "foo";
  char dest2[100] = "foo";
  char src[] = "bar";
  s21_strncat(dest1, src, 99);
  strncat(dest2, src, 99);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_concat_with_numbers) {
  char dest1[20] = "num";
  char dest2[20] = "num";
  char src[] = "12345";
  s21_strncat(dest1, src, 5);
  strncat(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncat");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_simple_concat);
  tcase_add_test(tc_core, test_n_greater_than_src);
  tcase_add_test(tc_core, test_n_zero);
  tcase_add_test(tc_core, test_empty_src);
  tcase_add_test(tc_core, test_empty_dest);
  tcase_add_test(tc_core, test_concat_with_null_in_src);
  tcase_add_test(tc_core, test_n_is_one);
  tcase_add_test(tc_core, test_long_src);
  tcase_add_test(tc_core, test_return_value);

  tcase_add_test(tc_core, test_concat_to_empty_with_n_zero);
  tcase_add_test(tc_core, test_concat_empty_src_and_dest);
  tcase_add_test(tc_core, test_concat_n_is_length_of_dest);
  tcase_add_test(tc_core, test_concat_with_special_chars);
  tcase_add_test(tc_core, test_concat_with_space);
  tcase_add_test(tc_core, test_concat_unicode);
  tcase_add_test(tc_core, test_concat_partial_unicode);
  tcase_add_test(tc_core, test_concat_n_is_zero_with_nonempty_dest);
  tcase_add_test(tc_core, test_concat_n_is_zero_with_nonempty_src);
  tcase_add_test(tc_core, test_concat_n_is_zero_with_both_empty);
  tcase_add_test(tc_core, test_concat_large_n);
  tcase_add_test(tc_core, test_concat_with_numbers);

  suite_add_tcase(s, tc_core);
  return s;
}
