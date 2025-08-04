#include <check.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(strlen_empty) { ck_assert_int_eq(s21_strlen(""), strlen("")); }
END_TEST
START_TEST(strlen_one_char) { ck_assert_int_eq(s21_strlen("a"), strlen("a")); }
END_TEST
START_TEST(strlen_short) { ck_assert_int_eq(s21_strlen("abc"), strlen("abc")); }
END_TEST
START_TEST(strlen_long) {
  char str[1001];
  memset(str, 'a', 1000);
  str[1000] = '\0';
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(strlen_with_space) {
  ck_assert_int_eq(s21_strlen("hello world"), strlen("hello world"));
}
END_TEST
START_TEST(strlen_with_newline) {
  ck_assert_int_eq(s21_strlen("hello\nworld"), strlen("hello\nworld"));
}
END_TEST
START_TEST(strlen_with_tab) {
  ck_assert_int_eq(s21_strlen("hello\tworld"), strlen("hello\tworld"));
}
END_TEST
START_TEST(strlen_unicode) {
  ck_assert_int_eq(s21_strlen("абвгд"), strlen("абвгд"));
}
END_TEST
START_TEST(strlen_special_chars) {
  ck_assert_int_eq(s21_strlen("!@#$%^&*()"), strlen("!@#$%^&*()"));
}
END_TEST
START_TEST(strlen_null_in_middle) {
  char str[] = {'a', 'b', '\0', 'c', '\0'};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_all_nulls) {
  char str[] = {'\0', '\0', '\0'};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_first_null) {
  char str[] = {'\0', 'a', 'b', 'c'};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_only_null) {
  char str[] = {'\0'};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_long_with_null_in_middle) {
  char str[1001];
  memset(str, 'x', 1000);
  str[500] = '\0';
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_ascii_extended) {
  char str[] = {127, 126, 125, 124, 0};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_non_ascii_bytes) {
  char str[] = {(char)0xC0, (char)0xD0, (char)0xE0, 0};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_with_multiple_spaces) {
  ck_assert_int_eq(s21_strlen("   "), strlen("   "));
}
END_TEST

START_TEST(strlen_with_escaped_chars) {
  ck_assert_int_eq(s21_strlen("a\\nb\\tc"), strlen("a\\nb\\tc"));
}
END_TEST

START_TEST(strlen_with_numbers) {
  ck_assert_int_eq(s21_strlen("1234567890"), strlen("1234567890"));
}
END_TEST

START_TEST(strlen_with_mixed_content) {
  ck_assert_int_eq(s21_strlen("abc123!@#\n\t "), strlen("abc123!@#\n\t "));
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, strlen_empty);
  tcase_add_test(tc, strlen_one_char);
  tcase_add_test(tc, strlen_short);
  tcase_add_test(tc, strlen_long);
  tcase_add_test(tc, strlen_with_space);
  tcase_add_test(tc, strlen_with_newline);
  tcase_add_test(tc, strlen_with_tab);
  tcase_add_test(tc, strlen_unicode);
  tcase_add_test(tc, strlen_special_chars);
  tcase_add_test(tc, strlen_null_in_middle);
  tcase_add_test(tc, strlen_all_nulls);
  tcase_add_test(tc, strlen_first_null);
  tcase_add_test(tc, strlen_only_null);
  tcase_add_test(tc, strlen_long_with_null_in_middle);
  tcase_add_test(tc, strlen_ascii_extended);
  tcase_add_test(tc, strlen_non_ascii_bytes);
  tcase_add_test(tc, strlen_with_multiple_spaces);
  tcase_add_test(tc, strlen_with_escaped_chars);
  tcase_add_test(tc, strlen_with_numbers);
  tcase_add_test(tc, strlen_with_mixed_content);
  suite_add_tcase(s, tc);
  return s;
}