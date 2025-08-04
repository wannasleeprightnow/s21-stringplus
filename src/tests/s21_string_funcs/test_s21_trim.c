#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(trim_no_trim_chars) {
  char *res = s21_trim("hello", "");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_no_trim_needed) {
  char *res = s21_trim("hello", " ");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_left) {
  char *res = s21_trim("   hello", " ");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_right) {
  char *res = s21_trim("hello   ", " ");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_both) {
  char *res = s21_trim("   hello   ", " ");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_all) {
  char *res = s21_trim("     ", " ");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_empty_src) {
  char *res = s21_trim("", " ");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_empty_trim_chars) {
  char *res = s21_trim("abc", "");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "abc");
  free(res);
}
END_TEST

START_TEST(trim_all_chars) {
  char *res = s21_trim("xxx", "x");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_partial_chars) {
  char *res = s21_trim("xyxabcxyx", "xy");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "abc");
  free(res);
}
END_TEST

START_TEST(trim_special_chars) {
  char *res = s21_trim("\n\t hello \t\n", " \n\t");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_unicode) {
  char *res = s21_trim("ааабабhelloббааа", "аб");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_no_trim_chars_in_src) {
  char *res = s21_trim("hello", "xyz");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_trim_chars_longer_than_src) {
  char *res = s21_trim("a", "abcdef");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_src_is_only_trim_chars) {
  char *res = s21_trim("xxx", "x");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_src_is_null) {
  char *res = s21_trim(NULL, " ");
  ck_assert_ptr_eq(res, NULL);
}
END_TEST

START_TEST(trim_trim_chars_is_empty_and_src_is_empty) {
  char *res = s21_trim("", "");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_one_char) {
  char *res = s21_trim("a", "a");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_one_char_not_trimmed) {
  char *res = s21_trim("a", "b");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "a");
  free(res);
}
END_TEST

START_TEST(trim_middle_trim_chars) {
  char *res = s21_trim("abchelloxyz", "abcxyz");
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

Suite *trim_suite(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, trim_no_trim_chars);
  tcase_add_test(tc, trim_no_trim_needed);
  tcase_add_test(tc, trim_left);
  tcase_add_test(tc, trim_right);
  tcase_add_test(tc, trim_both);
  tcase_add_test(tc, trim_all);
  tcase_add_test(tc, trim_empty_src);
  tcase_add_test(tc, trim_empty_trim_chars);
  tcase_add_test(tc, trim_all_chars);
  tcase_add_test(tc, trim_partial_chars);
  tcase_add_test(tc, trim_special_chars);
  tcase_add_test(tc, trim_unicode);
  tcase_add_test(tc, trim_no_trim_chars_in_src);
  tcase_add_test(tc, trim_trim_chars_longer_than_src);
  tcase_add_test(tc, trim_src_is_only_trim_chars);
  tcase_add_test(tc, trim_src_is_null);
  tcase_add_test(tc, trim_trim_chars_is_empty_and_src_is_empty);
  tcase_add_test(tc, trim_one_char);
  tcase_add_test(tc, trim_one_char_not_trimmed);
  tcase_add_test(tc, trim_middle_trim_chars);

  suite_add_tcase(s, tc);
  return s;
}