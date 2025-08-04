#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_equal_strings) {
  char a[] = "abcdef";
  char b[] = "abcdef";
  ck_assert_int_eq(s21_memcmp(a, b, 6), memcmp(a, b, 6));
}
END_TEST

START_TEST(test_first_less) {
  char a[] = "abcdee";
  char b[] = "abcdef";
  ck_assert_int_eq(s21_memcmp(a, b, 6), memcmp(a, b, 6));
}
END_TEST

START_TEST(test_first_greater) {
  char a[] = "abcdeg";
  char b[] = "abcdef";
  ck_assert_int_eq(s21_memcmp(a, b, 6), memcmp(a, b, 6));
}
END_TEST

START_TEST(test_zero_length) {
  char a[] = "abc";
  char b[] = "def";
  ck_assert_int_eq(s21_memcmp(a, b, 0), memcmp(a, b, 0));
}
END_TEST

START_TEST(test_partial_compare) {
  char a[] = "abcxyz";
  char b[] = "abcuvw";
  ck_assert_int_eq(s21_memcmp(a, b, 3), memcmp(a, b, 3));
}
END_TEST

START_TEST(test_compare_with_null_bytes) {
  char a[] = "abc\0def";
  char b[] = "abc\0xyz";
  ck_assert_int_eq(s21_memcmp(a, b, 7), memcmp(a, b, 7));
}
END_TEST

START_TEST(test_unsigned_characters) {
  unsigned char a[] = {0xFF, 0x00, 0x7F};
  unsigned char b[] = {0xFF, 0x00, 0x7E};
  ck_assert_int_eq(s21_memcmp(a, b, 3), memcmp(a, b, 3));
}
END_TEST

START_TEST(test_empty_strings) {
  char a[] = "";
  char b[] = "";
  ck_assert_int_eq(s21_memcmp(a, b, 1), memcmp(a, b, 1));
}
END_TEST

START_TEST(test_large_n) {
  char a[] = "abcdef";
  char b[] = "abcdez";
  ck_assert_int_eq(s21_memcmp(a, b, sizeof(a)), memcmp(a, b, sizeof(a)));
}
END_TEST

START_TEST(test_one_byte_difference) {
  char a[] = "a";
  char b[] = "b";
  ck_assert_int_eq(s21_memcmp(a, b, 1), memcmp(a, b, 1));
}
END_TEST

START_TEST(test_compare_first_byte_diff) {
  char a[] = "xbcdef";
  char b[] = "abcdef";
  ck_assert_int_eq(s21_memcmp(a, b, 6), memcmp(a, b, 6));
}
END_TEST

START_TEST(test_compare_last_byte_diff) {
  char a[] = "abcdea";
  char b[] = "abcdeb";
  ck_assert_int_eq(s21_memcmp(a, b, 6), memcmp(a, b, 6));
}
END_TEST

START_TEST(test_compare_within_null_bytes) {
  char a[] = {0, 1, 2, 3, 4, 5};
  char b[] = {0, 1, 2, 3, 4, 6};
  ck_assert_int_eq(s21_memcmp(a, b, 6), memcmp(a, b, 6));
}
END_TEST

START_TEST(test_compare_all_zeros) {
  char a[] = {0, 0, 0, 0, 0};
  char b[] = {0, 0, 0, 0, 0};
  ck_assert_int_eq(s21_memcmp(a, b, 5), memcmp(a, b, 5));
}
END_TEST

START_TEST(test_compare_negative_bytes) {
  char a[] = {-1, -2, -3};
  char b[] = {-1, -2, -4};
  ck_assert_int_eq(s21_memcmp(a, b, 3), memcmp(a, b, 3));
}
END_TEST

START_TEST(test_compare_large_buffers_equal) {
  char a[1000], b[1000];
  memset(a, 'A', 1000);
  memset(b, 'A', 1000);
  ck_assert_int_eq(s21_memcmp(a, b, 1000), memcmp(a, b, 1000));
}
END_TEST

START_TEST(test_compare_large_buffers_diff) {
  char a[1000], b[1000];
  memset(a, 'A', 1000);
  memset(b, 'A', 1000);
  b[999] = 'B';
  ck_assert_int_eq(s21_memcmp(a, b, 1000), memcmp(a, b, 1000));
}
END_TEST

START_TEST(test_compare_partial_with_nulls) {
  char a[] = "abc\0def";
  char b[] = "abc\0deg";
  ck_assert_int_eq(s21_memcmp(a, b, 5), memcmp(a, b, 5));
}
END_TEST

START_TEST(test_compare_unsigned_vs_signed) {
  unsigned char a[] = {0xFF, 0x7F};
  char b[] = {-1, 127};
  ck_assert_int_eq(s21_memcmp(a, b, 2), memcmp(a, b, 2));
}
END_TEST

START_TEST(test_compare_one_byte) {
  char a[] = {0x01};
  char b[] = {0x02};
  ck_assert_int_eq(s21_memcmp(a, b, 1), memcmp(a, b, 1));
}
END_TEST

START_TEST(test_compare_empty_buffers) {
  char a[] = "";
  char b[] = "";
  ck_assert_int_eq(s21_memcmp(a, b, 0), memcmp(a, b, 0));
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memcmp");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_equal_strings);
  tcase_add_test(tc_core, test_first_less);
  tcase_add_test(tc_core, test_first_greater);
  tcase_add_test(tc_core, test_zero_length);
  tcase_add_test(tc_core, test_partial_compare);
  tcase_add_test(tc_core, test_compare_with_null_bytes);
  tcase_add_test(tc_core, test_unsigned_characters);
  tcase_add_test(tc_core, test_empty_strings);
  tcase_add_test(tc_core, test_large_n);
  tcase_add_test(tc_core, test_one_byte_difference);
  tcase_add_test(tc_core, test_compare_first_byte_diff);
  tcase_add_test(tc_core, test_compare_last_byte_diff);
  tcase_add_test(tc_core, test_compare_within_null_bytes);
  tcase_add_test(tc_core, test_compare_all_zeros);
  tcase_add_test(tc_core, test_compare_negative_bytes);
  tcase_add_test(tc_core, test_compare_large_buffers_equal);
  tcase_add_test(tc_core, test_compare_large_buffers_diff);
  tcase_add_test(tc_core, test_compare_partial_with_nulls);
  tcase_add_test(tc_core, test_compare_unsigned_vs_signed);
  tcase_add_test(tc_core, test_compare_one_byte);
  tcase_add_test(tc_core, test_compare_empty_buffers);

  suite_add_tcase(s, tc_core);
  return s;
}