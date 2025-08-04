#include <check.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(strcspn_empty_strings) {
  ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
}
END_TEST
START_TEST(strcspn_no_match) {
  ck_assert_int_eq(s21_strcspn("abcdef", "xyz"), strcspn("abcdef", "xyz"));
}
END_TEST
START_TEST(strcspn_first_char_match) {
  ck_assert_int_eq(s21_strcspn("abcdef", "a"), strcspn("abcdef", "a"));
}
END_TEST
START_TEST(strcspn_last_char_match) {
  ck_assert_int_eq(s21_strcspn("abcdef", "f"), strcspn("abcdef", "f"));
}
END_TEST
START_TEST(strcspn_middle_char_match) {
  ck_assert_int_eq(s21_strcspn("abcdef", "d"), strcspn("abcdef", "d"));
}
END_TEST
START_TEST(strcspn_all_match) {
  ck_assert_int_eq(s21_strcspn("abcdef", "abcdef"),
                   strcspn("abcdef", "abcdef"));
}
END_TEST
START_TEST(strcspn_empty_str2) {
  ck_assert_int_eq(s21_strcspn("abcdef", ""), strcspn("abcdef", ""));
}
END_TEST
START_TEST(strcspn_empty_str1) {
  ck_assert_int_eq(s21_strcspn("", "abc"), strcspn("", "abc"));
}
END_TEST
START_TEST(strcspn_unicode) {
  ck_assert_int_eq(s21_strcspn("абвгд", "гд"), strcspn("абвгд", "гд"));
}
END_TEST
START_TEST(strcspn_special_chars) {
  ck_assert_int_eq(s21_strcspn("a!@#b", "!@#"), strcspn("a!@#b", "!@#"));
}
END_TEST

START_TEST(strcspn_no_match_empty_str1) {
  ck_assert_int_eq(s21_strcspn("", "xyz"), strcspn("", "xyz"));
}
END_TEST

START_TEST(strcspn_str2_longer_than_str1) {
  ck_assert_int_eq(s21_strcspn("abc", "abcdefghijklmnopqrstuvwxyz"),
                   strcspn("abc", "abcdefghijklmnopqrstuvwxyz"));
}
END_TEST

START_TEST(strcspn_str1_contains_null) {
  char str1[] = "abc\0def";
  char str2[] = "d";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_str2_contains_null) {
  char str1[] = "abcdef";
  char str2[] = "d\0f";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_both_contain_null) {
  char str1[] = "abc\0def";
  char str2[] = "e\0f";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_first_char_match_in_str2) {
  ck_assert_int_eq(s21_strcspn("abcdef", "a123"), strcspn("abcdef", "a123"));
}
END_TEST

START_TEST(strcspn_last_char_match_in_str2) {
  ck_assert_int_eq(s21_strcspn("abcdef", "123f"), strcspn("abcdef", "123f"));
}
END_TEST

START_TEST(strcspn_multiple_matches) {
  ck_assert_int_eq(s21_strcspn("abcdef", "bdf"), strcspn("abcdef", "bdf"));
}
END_TEST

START_TEST(strcspn_repeated_chars_in_str2) {
  ck_assert_int_eq(s21_strcspn("abcdef", "aaa"), strcspn("abcdef", "aaa"));
}
END_TEST

START_TEST(strcspn_str1_all_in_str2) {
  ck_assert_int_eq(s21_strcspn("abc", "cba"), strcspn("abc", "cba"));
}
END_TEST

START_TEST(strcspn_str2_is_space) {
  ck_assert_int_eq(s21_strcspn("hello world", " "),
                   strcspn("hello world", " "));
}
END_TEST

START_TEST(strcspn_str2_is_newline) {
  ck_assert_int_eq(s21_strcspn("line1\nline2", "\n"),
                   strcspn("line1\nline2", "\n"));
}
END_TEST

START_TEST(strcspn_str1_starts_with_match) {
  ck_assert_int_eq(s21_strcspn("aabcdef", "a"), strcspn("aabcdef", "a"));
}
END_TEST

START_TEST(strcspn_str1_ends_with_match) {
  ck_assert_int_eq(s21_strcspn("abcdefa", "a"), strcspn("abcdefa", "a"));
}
END_TEST

START_TEST(strcspn_str2_empty_and_str1_nonempty) {
  ck_assert_int_eq(s21_strcspn("abcdef", ""), strcspn("abcdef", ""));
}
END_TEST

START_TEST(strcspn_str1_empty_and_str2_nonempty) {
  ck_assert_int_eq(s21_strcspn("", "abcdef"), strcspn("", "abcdef"));
}
END_TEST

START_TEST(strcspn_both_empty) {
  ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, strcspn_empty_strings);
  tcase_add_test(tc, strcspn_no_match);
  tcase_add_test(tc, strcspn_first_char_match);
  tcase_add_test(tc, strcspn_last_char_match);
  tcase_add_test(tc, strcspn_middle_char_match);
  tcase_add_test(tc, strcspn_all_match);
  tcase_add_test(tc, strcspn_empty_str2);
  tcase_add_test(tc, strcspn_empty_str1);
  tcase_add_test(tc, strcspn_unicode);
  tcase_add_test(tc, strcspn_special_chars);
  tcase_add_test(tc, strcspn_no_match_empty_str1);
  tcase_add_test(tc, strcspn_str2_longer_than_str1);
  tcase_add_test(tc, strcspn_str1_contains_null);
  tcase_add_test(tc, strcspn_str2_contains_null);
  tcase_add_test(tc, strcspn_both_contain_null);
  tcase_add_test(tc, strcspn_first_char_match_in_str2);
  tcase_add_test(tc, strcspn_last_char_match_in_str2);
  tcase_add_test(tc, strcspn_multiple_matches);
  tcase_add_test(tc, strcspn_repeated_chars_in_str2);
  tcase_add_test(tc, strcspn_str1_all_in_str2);
  tcase_add_test(tc, strcspn_str2_is_space);
  tcase_add_test(tc, strcspn_str2_is_newline);
  tcase_add_test(tc, strcspn_str1_starts_with_match);
  tcase_add_test(tc, strcspn_str1_ends_with_match);
  tcase_add_test(tc, strcspn_str2_empty_and_str1_nonempty);
  tcase_add_test(tc, strcspn_str1_empty_and_str2_nonempty);
  tcase_add_test(tc, strcspn_both_empty);
  suite_add_tcase(s, tc);
  return s;
}