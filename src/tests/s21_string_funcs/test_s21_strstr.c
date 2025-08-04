#include <check.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(strstr_basic) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "cd"), strstr("abcdef", "cd"));
}
END_TEST
START_TEST(strstr_no_match) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "xyz"), strstr("abcdef", "xyz"));
}
END_TEST
START_TEST(strstr_empty_needle) {
  ck_assert_ptr_eq(s21_strstr("abcdef", ""), strstr("abcdef", ""));
}
END_TEST
START_TEST(strstr_empty_haystack) {
  ck_assert_ptr_eq(s21_strstr("", "abc"), strstr("", "abc"));
}
END_TEST
START_TEST(strstr_both_empty) {
  ck_assert_ptr_eq(s21_strstr("", ""), strstr("", ""));
}
END_TEST
START_TEST(strstr_full_match) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "abcdef"), strstr("abcdef", "abcdef"));
}
END_TEST
START_TEST(strstr_partial_overlap) {
  ck_assert_ptr_eq(s21_strstr("abcabcabc", "bca"), strstr("abcabcabc", "bca"));
}
END_TEST
START_TEST(strstr_unicode) {
  ck_assert_ptr_eq(s21_strstr("абвгд", "вг"), strstr("абвгд", "вг"));
}
END_TEST
START_TEST(strstr_special_chars) {
  ck_assert_ptr_eq(s21_strstr("a!@#b", "!@#"), strstr("a!@#b", "!@#"));
}
END_TEST
START_TEST(strstr_one_char) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "e"), strstr("abcdef", "e"));
}
END_TEST

START_TEST(strstr_needle_at_start) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "abc"), strstr("abcdef", "abc"));
}
END_TEST

START_TEST(strstr_needle_at_end) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "def"), strstr("abcdef", "def"));
}
END_TEST

START_TEST(strstr_needle_is_haystack) {
  ck_assert_ptr_eq(s21_strstr("abc", "abc"), strstr("abc", "abc"));
}
END_TEST

START_TEST(strstr_needle_longer_than_haystack) {
  ck_assert_ptr_eq(s21_strstr("abc", "abcd"), strstr("abc", "abcd"));
}
END_TEST

START_TEST(strstr_haystack_with_null) {
  char haystack[] = "abc\0def";
  char needle[] = "def";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_needle_with_null) {
  char haystack[] = "abcdef";
  char needle[] = "de\0f";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_both_with_null) {
  char haystack[] = "abc\0def";
  char needle[] = "\0d";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_repeated_needle) {
  ck_assert_ptr_eq(s21_strstr("abababab", "aba"), strstr("abababab", "aba"));
}
END_TEST

START_TEST(strstr_needle_not_in_haystack) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "gh"), strstr("abcdef", "gh"));
}
END_TEST

START_TEST(strstr_needle_is_space) {
  ck_assert_ptr_eq(s21_strstr("a b c d", " "), strstr("a b c d", " "));
}
END_TEST

START_TEST(strstr_needle_is_special_char) {
  ck_assert_ptr_eq(s21_strstr("foo@bar.com", "@"), strstr("foo@bar.com", "@"));
}
END_TEST

START_TEST(strstr_needle_is_newline) {
  ck_assert_ptr_eq(s21_strstr("line1\nline2", "\n"),
                   strstr("line1\nline2", "\n"));
}
END_TEST

START_TEST(strstr_needle_is_tab) {
  ck_assert_ptr_eq(s21_strstr("a\tb\tc", "\t"), strstr("a\tb\tc", "\t"));
}
END_TEST

START_TEST(strstr_needle_repeats_in_haystack) {
  ck_assert_ptr_eq(s21_strstr("abcabcabc", "abc"), strstr("abcabcabc", "abc"));
}
END_TEST

START_TEST(strstr_needle_is_last_char) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "f"), strstr("abcdef", "f"));
}
END_TEST

START_TEST(strstr_needle_is_first_char) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "a"), strstr("abcdef", "a"));
}
END_TEST

START_TEST(strstr_needle_is_middle_char) {
  ck_assert_ptr_eq(s21_strstr("abcdef", "d"), strstr("abcdef", "d"));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, strstr_basic);
  tcase_add_test(tc, strstr_no_match);
  tcase_add_test(tc, strstr_empty_needle);
  tcase_add_test(tc, strstr_empty_haystack);
  tcase_add_test(tc, strstr_both_empty);
  tcase_add_test(tc, strstr_full_match);
  tcase_add_test(tc, strstr_partial_overlap);
  tcase_add_test(tc, strstr_unicode);
  tcase_add_test(tc, strstr_special_chars);
  tcase_add_test(tc, strstr_one_char);
  tcase_add_test(tc, strstr_needle_at_start);
  tcase_add_test(tc, strstr_needle_at_end);
  tcase_add_test(tc, strstr_needle_is_haystack);
  tcase_add_test(tc, strstr_needle_longer_than_haystack);
  tcase_add_test(tc, strstr_haystack_with_null);
  tcase_add_test(tc, strstr_needle_with_null);
  tcase_add_test(tc, strstr_both_with_null);
  tcase_add_test(tc, strstr_repeated_needle);
  tcase_add_test(tc, strstr_needle_not_in_haystack);
  tcase_add_test(tc, strstr_needle_is_space);
  tcase_add_test(tc, strstr_needle_is_special_char);
  tcase_add_test(tc, strstr_needle_is_newline);
  tcase_add_test(tc, strstr_needle_is_tab);
  tcase_add_test(tc, strstr_needle_repeats_in_haystack);
  tcase_add_test(tc, strstr_needle_is_last_char);
  tcase_add_test(tc, strstr_needle_is_first_char);
  tcase_add_test(tc, strstr_needle_is_middle_char);
  suite_add_tcase(s, tc);
  return s;
}