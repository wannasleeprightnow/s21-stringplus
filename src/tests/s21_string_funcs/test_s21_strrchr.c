#include <check.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(strrchr_basic) {
  ck_assert_ptr_eq(s21_strrchr("abcdefabc", 'a'), strrchr("abcdefabc", 'a'));
}
END_TEST
START_TEST(strrchr_no_match) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'z'), strrchr("abcdef", 'z'));
}
END_TEST
START_TEST(strrchr_first_char) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'a'), strrchr("abcdef", 'a'));
}
END_TEST
START_TEST(strrchr_last_char) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'f'), strrchr("abcdef", 'f'));
}
END_TEST
START_TEST(strrchr_middle_char) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'd'), strrchr("abcdef", 'd'));
}
END_TEST
START_TEST(strrchr_multiple) {
  ck_assert_ptr_eq(s21_strrchr("abacadae", 'a'), strrchr("abacadae", 'a'));
}
END_TEST
START_TEST(strrchr_null_byte) {
  char str[] = "abc\0def";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST
START_TEST(strrchr_empty) {
  ck_assert_ptr_eq(s21_strrchr("", 'a'), strrchr("", 'a'));
}
END_TEST
START_TEST(strrchr_unicode) {
  ck_assert_ptr_eq(s21_strrchr("abcdefa", 'a'), strrchr("abcdefa", 'a'));
}
END_TEST
START_TEST(strrchr_special_chars) {
  ck_assert_ptr_eq(s21_strrchr("!@#a!@#", '!'), strrchr("!@#a!@#", '!'));
}
END_TEST

START_TEST(strrchr_match_at_second_char) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'b'), strrchr("abcdef", 'b'));
}
END_TEST

START_TEST(strrchr_match_at_penultimate_char) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'e'), strrchr("abcdef", 'e'));
}
END_TEST

START_TEST(strrchr_match_with_space) {
  ck_assert_ptr_eq(s21_strrchr("hello world", ' '),
                   strrchr("hello world", ' '));
}
END_TEST

START_TEST(strrchr_match_with_newline) {
  ck_assert_ptr_eq(s21_strrchr("line1\nline2", '\n'),
                   strrchr("line1\nline2", '\n'));
}
END_TEST

START_TEST(strrchr_match_with_tab) {
  ck_assert_ptr_eq(s21_strrchr("a\tb\tc", '\t'), strrchr("a\tb\tc", '\t'));
}
END_TEST

START_TEST(strrchr_match_with_numbers) {
  ck_assert_ptr_eq(s21_strrchr("abc123123", '1'), strrchr("abc123123", '1'));
}
END_TEST

START_TEST(strrchr_match_with_repeated_chars) {
  ck_assert_ptr_eq(s21_strrchr("aaaaaa", 'a'), strrchr("aaaaaa", 'a'));
}
END_TEST

START_TEST(strrchr_str_contains_null) {
  char str[] = "abc\0def\0ghi";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_match_first_of_many) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'a'), strrchr("abcdef", 'a'));
}
END_TEST

START_TEST(strrchr_match_last_of_many) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'f'), strrchr("abcdef", 'f'));
}
END_TEST

START_TEST(strrchr_match_with_special_chars) {
  ck_assert_ptr_eq(s21_strrchr("foo@bar.com@", '@'),
                   strrchr("foo@bar.com@", '@'));
}
END_TEST

START_TEST(strrchr_match_with_all_chars) {
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'f'), strrchr("abcdef", 'f'));
}
END_TEST

START_TEST(strrchr_match_with_repeated_str) {
  ck_assert_ptr_eq(s21_strrchr("abcdefabcdef", 'd'),
                   strrchr("abcdefabcdef", 'd'));
}
END_TEST

START_TEST(strrchr_match_with_null_at_start) {
  char str[] = "\0abc";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_match_with_null_at_end) {
  char str[] = "abc\0";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_match_with_empty_and_null) {
  char str[] = "";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, strrchr_basic);
  tcase_add_test(tc, strrchr_no_match);
  tcase_add_test(tc, strrchr_first_char);
  tcase_add_test(tc, strrchr_last_char);
  tcase_add_test(tc, strrchr_middle_char);
  tcase_add_test(tc, strrchr_multiple);
  tcase_add_test(tc, strrchr_null_byte);
  tcase_add_test(tc, strrchr_empty);
  tcase_add_test(tc, strrchr_unicode);
  tcase_add_test(tc, strrchr_special_chars);
  tcase_add_test(tc, strrchr_match_at_second_char);
  tcase_add_test(tc, strrchr_match_at_penultimate_char);
  tcase_add_test(tc, strrchr_match_with_space);
  tcase_add_test(tc, strrchr_match_with_newline);
  tcase_add_test(tc, strrchr_match_with_tab);
  tcase_add_test(tc, strrchr_match_with_numbers);
  tcase_add_test(tc, strrchr_match_with_repeated_chars);
  tcase_add_test(tc, strrchr_str_contains_null);
  tcase_add_test(tc, strrchr_match_first_of_many);
  tcase_add_test(tc, strrchr_match_last_of_many);
  tcase_add_test(tc, strrchr_match_with_special_chars);
  tcase_add_test(tc, strrchr_match_with_all_chars);
  tcase_add_test(tc, strrchr_match_with_repeated_str);
  tcase_add_test(tc, strrchr_match_with_null_at_start);
  tcase_add_test(tc, strrchr_match_with_null_at_end);
  tcase_add_test(tc, strrchr_match_with_empty_and_null);
  suite_add_tcase(s, tc);
  return s;
}