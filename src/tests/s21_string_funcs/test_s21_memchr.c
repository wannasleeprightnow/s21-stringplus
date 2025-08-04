#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_found_in_middle) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'c', 6), memchr(str, 'c', 6));
}
END_TEST

START_TEST(test_not_found) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'x', 6), memchr(str, 'x', 6));
}
END_TEST

START_TEST(test_found_at_start) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'a', 6), memchr(str, 'a', 6));
}
END_TEST

START_TEST(test_found_at_end) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'f', 6), memchr(str, 'f', 6));
}
END_TEST

START_TEST(test_zero_length) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'a', 0), memchr(str, 'a', 0));
}
END_TEST

START_TEST(test_search_null_byte) {
  char str[] = "abc\0def";
  ck_assert_ptr_eq(s21_memchr(str, '\0', 7), memchr(str, '\0', 7));
}
END_TEST

START_TEST(test_multiple_occurrences) {
  char str[] = "abacadae";
  ck_assert_ptr_eq(s21_memchr(str, 'a', 8), memchr(str, 'a', 8));
}
END_TEST

START_TEST(test_unsigned_char) {
  unsigned char arr[] = {0xFF, 0x00, 0x7F};
  ck_assert_ptr_eq(s21_memchr(arr, 0xFF, 3), memchr(arr, 0xFF, 3));
}
END_TEST

START_TEST(test_large_n) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'd', sizeof(str)),
                   memchr(str, 'd', sizeof(str)));
}
END_TEST

START_TEST(test_empty_string) {
  char str[] = "";
  ck_assert_ptr_eq(s21_memchr(str, 'a', 1), memchr(str, 'a', 1));
}
END_TEST

START_TEST(test_search_beyond_null_terminator) {
  char str[] = "abc\0def";
  ck_assert_ptr_eq(s21_memchr(str, 'd', 7), memchr(str, 'd', 7));
}
END_TEST

START_TEST(test_search_last_byte) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str + 5, 'f', 1), memchr(str + 5, 'f', 1));
}
END_TEST

START_TEST(test_search_first_byte_only) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'a', 1), memchr(str, 'a', 1));
}
END_TEST

START_TEST(test_search_non_ascii) {
  unsigned char arr[] = {0x80, 0x81, 0x82, 0x83};
  ck_assert_ptr_eq(s21_memchr(arr, 0x82, 4), memchr(arr, 0x82, 4));
}
END_TEST

START_TEST(test_search_negative_char) {
  char arr[] = {1, -2, 3, -4, 5};
  ck_assert_ptr_eq(s21_memchr(arr, -2, 5), memchr(arr, -2, 5));
}
END_TEST

START_TEST(test_search_zero_in_middle) {
  char arr[] = {1, 2, 0, 4, 5};
  ck_assert_ptr_eq(s21_memchr(arr, 0, 5), memchr(arr, 0, 5));
}
END_TEST

START_TEST(test_search_all_bytes_same) {
  char arr[10];
  memset(arr, 'x', 10);
  ck_assert_ptr_eq(s21_memchr(arr, 'x', 10), memchr(arr, 'x', 10));
}
END_TEST

START_TEST(test_search_value_greater_than_uchar) {
  char arr[] = {1, 2, 3, 4, 5};
  ck_assert_ptr_eq(s21_memchr(arr, 257, 5), memchr(arr, 257, 5));
}
END_TEST

START_TEST(test_search_value_less_than_zero) {
  char arr[] = {1, 2, 3, 4, 5};
  ck_assert_ptr_eq(s21_memchr(arr, -255, 5), memchr(arr, -255, 5));
}
END_TEST

START_TEST(test_search_in_large_buffer) {
  char *arr = malloc(10000);
  memset(arr, 'A', 10000);
  arr[9999] = 'Z';
  ck_assert_ptr_eq(s21_memchr(arr, 'Z', 10000), memchr(arr, 'Z', 10000));
  free(arr);
}
END_TEST

START_TEST(test_search_in_large_buffer_not_found) {
  char *arr = malloc(10000);
  memset(arr, 'A', 10000);
  ck_assert_ptr_eq(s21_memchr(arr, 'Z', 10000), memchr(arr, 'Z', 10000));
  free(arr);
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memchr");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_found_in_middle);
  tcase_add_test(tc_core, test_not_found);
  tcase_add_test(tc_core, test_found_at_start);
  tcase_add_test(tc_core, test_found_at_end);
  tcase_add_test(tc_core, test_zero_length);
  tcase_add_test(tc_core, test_search_null_byte);
  tcase_add_test(tc_core, test_multiple_occurrences);
  tcase_add_test(tc_core, test_unsigned_char);
  tcase_add_test(tc_core, test_large_n);
  tcase_add_test(tc_core, test_empty_string);
  tcase_add_test(tc_core, test_search_beyond_null_terminator);
  tcase_add_test(tc_core, test_search_last_byte);
  tcase_add_test(tc_core, test_search_first_byte_only);
  tcase_add_test(tc_core, test_search_non_ascii);
  tcase_add_test(tc_core, test_search_negative_char);
  tcase_add_test(tc_core, test_search_zero_in_middle);
  tcase_add_test(tc_core, test_search_all_bytes_same);
  tcase_add_test(tc_core, test_search_value_greater_than_uchar);
  tcase_add_test(tc_core, test_search_value_less_than_zero);
  tcase_add_test(tc_core, test_search_in_large_buffer);
  tcase_add_test(tc_core, test_search_in_large_buffer_not_found);

  suite_add_tcase(s, tc_core);
  return s;
}