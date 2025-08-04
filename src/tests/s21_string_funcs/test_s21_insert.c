#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_s21_insert_middle) {
  char *res = (char *)s21_insert("HelloWorld", " ", 5);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "Hello World");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_beginning) {
  char *res = (char *)s21_insert("World", "Hello ", 0);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "Hello World");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_end) {
  char *res = (char *)s21_insert("Hello", " World", 5);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "Hello World");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_empty_src) {
  char *res = (char *)s21_insert("", "Hello", 0);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "Hello");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_empty_str) {
  char *res = (char *)s21_insert("Hello", "", 3);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "Hello");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_both_empty) {
  char *res = (char *)s21_insert("", "", 0);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_invalid_index) {
  char *res = (char *)s21_insert("Hello", "World", 10);
  ck_assert_ptr_eq(res, S21_NULL);
}
END_TEST

START_TEST(test_s21_insert_null_src) {
  char *res = (char *)s21_insert(S21_NULL, "World", 0);
  ck_assert_ptr_eq(res, S21_NULL);
}
END_TEST

START_TEST(test_s21_insert_null_str) {
  char *res = (char *)s21_insert("Hello", S21_NULL, 0);
  ck_assert_ptr_eq(res, S21_NULL);
}
END_TEST

START_TEST(test_s21_insert_zero_index) {
  char *res = (char *)s21_insert("abc", "X", 0);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "Xabc");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_last_index) {
  char *res = (char *)s21_insert("abc", "X", 2);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "abXc");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_after_last_char) {
  char *res = (char *)s21_insert("abc", "X", 3);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "abcX");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_full_overlap) {
  char *res = (char *)s21_insert("abc", "abc", 0);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "abcabc");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_long_string) {
  char src[1024] = {0};
  char str[1024] = {0};
  memset(src, 'A', 1000);
  memset(str, 'B', 100);
  src[1000] = '\0';
  str[100] = '\0';
  char *res = (char *)s21_insert(src, str, 500);
  ck_assert_ptr_nonnull(res);
  for (int i = 0; i < 500; ++i) ck_assert_int_eq(res[i], 'A');
  for (int i = 500; i < 600; ++i) ck_assert_int_eq(res[i], 'B');
  for (int i = 600; i < 1100; ++i) ck_assert_int_eq(res[i], 'A');
  ck_assert_int_eq(res[1100], '\0');
  free(res);
}
END_TEST
START_TEST(test_s21_insert_empty_str_at_end) {
  char *res = (char *)s21_insert("abc", "", 3);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "abc");
  free(res);
}
END_TEST

START_TEST(test_s21_insert_empty_str_at_beginning) {
  char *res = (char *)s21_insert("abc", "", 0);
  ck_assert_ptr_nonnull(res);
  ck_assert_str_eq(res, "abc");
  free(res);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_s21_insert_middle);
  tcase_add_test(tc, test_s21_insert_beginning);
  tcase_add_test(tc, test_s21_insert_end);
  tcase_add_test(tc, test_s21_insert_empty_src);
  tcase_add_test(tc, test_s21_insert_empty_str);
  tcase_add_test(tc, test_s21_insert_both_empty);
  tcase_add_test(tc, test_s21_insert_invalid_index);
  tcase_add_test(tc, test_s21_insert_null_src);
  tcase_add_test(tc, test_s21_insert_null_str);
  tcase_add_test(tc, test_s21_insert_zero_index);
  tcase_add_test(tc, test_s21_insert_last_index);
  tcase_add_test(tc, test_s21_insert_after_last_char);
  tcase_add_test(tc, test_s21_insert_full_overlap);
  tcase_add_test(tc, test_s21_insert_long_string);
  tcase_add_test(tc, test_s21_insert_empty_str_at_end);
  tcase_add_test(tc, test_s21_insert_empty_str_at_beginning);

  suite_add_tcase(s, tc);
  return s;
}