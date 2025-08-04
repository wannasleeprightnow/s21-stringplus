#include <check.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(strpbrk_basic) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "d"), strpbrk("abcdef", "d"));
}
END_TEST
START_TEST(strpbrk_no_match) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "xyz"), strpbrk("abcdef", "xyz"));
}
END_TEST
START_TEST(strpbrk_first_char) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "a"), strpbrk("abcdef", "a"));
}
END_TEST
START_TEST(strpbrk_last_char) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "f"), strpbrk("abcdef", "f"));
}
END_TEST
START_TEST(strpbrk_multiple_match) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "bdf"), strpbrk("abcdef", "bdf"));
}
END_TEST
START_TEST(strpbrk_empty_str1) {
  ck_assert_ptr_eq(s21_strpbrk("", "abc"), strpbrk("", "abc"));
}
END_TEST
START_TEST(strpbrk_empty_str2) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", ""), strpbrk("abcdef", ""));
}
END_TEST
START_TEST(strpbrk_both_empty) {
  ck_assert_ptr_eq(s21_strpbrk("", ""), strpbrk("", ""));
}
END_TEST
START_TEST(strpbrk_unicode) {
  ck_assert_ptr_eq(s21_strpbrk("абвгд", "гд"), strpbrk("абвгд", "гд"));
}
END_TEST
START_TEST(strpbrk_special_chars) {
  ck_assert_ptr_eq(s21_strpbrk("a!@#b", "!@#"), strpbrk("a!@#b", "!@#"));
}
END_TEST

START_TEST(strpbrk_match_at_second_char) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "b"), strpbrk("abcdef", "b"));
}
END_TEST

START_TEST(strpbrk_match_at_penultimate_char) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "e"), strpbrk("abcdef", "e"));
}
END_TEST

START_TEST(strpbrk_match_with_space) {
  ck_assert_ptr_eq(s21_strpbrk("hello world", " "),
                   strpbrk("hello world", " "));
}
END_TEST

START_TEST(strpbrk_match_with_newline) {
  ck_assert_ptr_eq(s21_strpbrk("line1\nline2", "\n"),
                   strpbrk("line1\nline2", "\n"));
}
END_TEST

START_TEST(strpbrk_match_with_tab) {
  ck_assert_ptr_eq(s21_strpbrk("a\tb\tc", "\t"), strpbrk("a\tb\tc", "\t"));
}
END_TEST

START_TEST(strpbrk_match_with_numbers) {
  ck_assert_ptr_eq(s21_strpbrk("abc123", "123"), strpbrk("abc123", "123"));
}
END_TEST

START_TEST(strpbrk_match_with_repeated_chars) {
  ck_assert_ptr_eq(s21_strpbrk("aaaaaa", "a"), strpbrk("aaaaaa", "a"));
}
END_TEST

START_TEST(strpbrk_str2_longer_than_str1) {
  ck_assert_ptr_eq(s21_strpbrk("abc", "abcdefghijklmnopqrstuvwxyz"),
                   strpbrk("abc", "abcdefghijklmnopqrstuvwxyz"));
}
END_TEST

START_TEST(strpbrk_str1_contains_null) {
  char str1[] = "abc\0def";
  char str2[] = "d";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_str2_contains_null) {
  char str1[] = "abcdef";
  char str2[] = "d\0f";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_both_contain_null) {
  char str1[] = "abc\0def";
  char str2[] = "e\0f";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_match_first_of_many) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "fa"), strpbrk("abcdef", "fa"));
}
END_TEST

START_TEST(strpbrk_match_last_of_many) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "xyzf"), strpbrk("abcdef", "xyzf"));
}
END_TEST

START_TEST(strpbrk_match_with_special_chars) {
  ck_assert_ptr_eq(s21_strpbrk("foo@bar.com", "@."),
                   strpbrk("foo@bar.com", "@."));
}
END_TEST

START_TEST(strpbrk_match_with_all_chars) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "abcdef"),
                   strpbrk("abcdef", "abcdef"));
}
END_TEST

START_TEST(strpbrk_match_with_repeated_str2) {
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "aaa"), strpbrk("abcdef", "aaa"));
}

Suite *strpbrk_suite(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, strpbrk_basic);
  tcase_add_test(tc, strpbrk_no_match);
  tcase_add_test(tc, strpbrk_first_char);
  tcase_add_test(tc, strpbrk_last_char);
  tcase_add_test(tc, strpbrk_multiple_match);
  tcase_add_test(tc, strpbrk_empty_str1);
  tcase_add_test(tc, strpbrk_empty_str2);
  tcase_add_test(tc, strpbrk_both_empty);
  tcase_add_test(tc, strpbrk_unicode);
  tcase_add_test(tc, strpbrk_special_chars);
  tcase_add_test(tc, strpbrk_match_at_second_char);
  tcase_add_test(tc, strpbrk_match_at_penultimate_char);
  tcase_add_test(tc, strpbrk_match_with_space);
  tcase_add_test(tc, strpbrk_match_with_newline);
  tcase_add_test(tc, strpbrk_match_with_tab);
  tcase_add_test(tc, strpbrk_match_with_numbers);
  tcase_add_test(tc, strpbrk_match_with_repeated_chars);
  tcase_add_test(tc, strpbrk_str2_longer_than_str1);
  tcase_add_test(tc, strpbrk_str1_contains_null);
  tcase_add_test(tc, strpbrk_str2_contains_null);
  tcase_add_test(tc, strpbrk_both_contain_null);
  tcase_add_test(tc, strpbrk_match_first_of_many);
  tcase_add_test(tc, strpbrk_match_last_of_many);
  tcase_add_test(tc, strpbrk_match_with_special_chars);
  tcase_add_test(tc, strpbrk_match_with_all_chars);
  tcase_add_test(tc, strpbrk_match_with_repeated_str2);
  suite_add_tcase(s, tc);
  return s;
}