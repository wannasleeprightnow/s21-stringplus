#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_copy_full_string) {
  char src[] = "hello";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_with_n_greater_than_src) {
  char src[] = "hi";
  char dest1[5] = {0};
  char dest2[5] = {0};
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_with_n_less_than_src) {
  char src[] = "abcdef";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);
  ck_assert_mem_eq(dest1, dest2, 3);
}
END_TEST

START_TEST(test_copy_empty_src) {
  char src[] = "";
  char dest1[5] = "1234";
  char dest2[5] = "1234";
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_with_null_in_src) {
  char src[] = "ab\0cd";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 6);
  strncpy(dest2, src, 6);
  ck_assert_mem_eq(dest1, dest2, 6);
}
END_TEST

START_TEST(test_copy_one_byte) {
  char src[] = "xyz";
  char dest1[5] = "test";
  char dest2[5] = "test";
  s21_strncpy(dest1, src, 1);
  strncpy(dest2, src, 1);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_to_self) {
  char buf[10] = "abcdef";
  s21_strncpy(buf, buf, 6);
  ck_assert_mem_eq(buf, "abcdef", 6);
}
END_TEST

START_TEST(test_return_value) {
  char src[] = "abc";
  char dest[10] = {0};
  char *ret = s21_strncpy(dest, src, 3);
  ck_assert_ptr_eq(ret, dest);
}
END_TEST

START_TEST(test_copy_large_buffer) {
  char src[1000];
  char dest1[1000];
  char dest2[1000];
  for (int i = 0; i < 1000; i++) src[i] = (char)(i % 256);
  s21_strncpy(dest1, src, 1000);
  strncpy(dest2, src, 1000);
  ck_assert_mem_eq(dest1, dest2, 1000);
}
END_TEST

START_TEST(test_copy_empty_src_n_one) {
  char src[] = "";
  char dest1[5] = "abcd";
  char dest2[5] = "abcd";
  s21_strncpy(dest1, src, 1);
  strncpy(dest2, src, 1);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_partial_with_null_in_src) {
  char src[] = "ab\0cd";
  char dest1[10] = "XXXXXXXXX";
  char dest2[10] = "XXXXXXXXX";
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);
  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(test_copy_with_special_chars) {
  char src[] = "!@#\n\t";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_unicode) {
  char src[] = "абв";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 6);
  strncpy(dest2, src, 6);
  ck_assert_mem_eq(dest1, dest2, 6);
}
END_TEST

START_TEST(test_copy_partial_unicode) {
  char src[] = "абв";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 2);
  strncpy(dest2, src, 2);
  ck_assert_mem_eq(dest1, dest2, 2);
}
END_TEST

START_TEST(test_copy_to_middle_of_dest) {
  char src[] = "abc";
  char dest1[10] = "XXXXXXXXX";
  char dest2[10] = "XXXXXXXXX";
  s21_strncpy(dest1 + 2, src, 3);
  strncpy(dest2 + 2, src, 3);
  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(test_copy_with_numbers) {
  char src[] = "12345";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_with_space) {
  char src[] = "hello world";
  char dest1[20] = {0};
  char dest2[20] = {0};
  s21_strncpy(dest1, src, 11);
  strncpy(dest2, src, 11);
  ck_assert_mem_eq(dest1, dest2, 11);
}
END_TEST

START_TEST(test_copy_with_tab_and_newline) {
  char src[] = "a\tb\nc";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_with_non_ascii) {
  char src[] = {0xC0, 0xC1, 0xC2, 0};
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_strncpy(dest1, src, 4);
  strncpy(dest2, src, 4);
  ck_assert_mem_eq(dest1, dest2, 4);
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncpy");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_copy_full_string);
  tcase_add_test(tc_core, test_copy_with_n_greater_than_src);
  tcase_add_test(tc_core, test_copy_with_n_less_than_src);
  tcase_add_test(tc_core, test_copy_empty_src);
  tcase_add_test(tc_core, test_copy_with_null_in_src);
  tcase_add_test(tc_core, test_copy_one_byte);
  tcase_add_test(tc_core, test_copy_to_self);
  tcase_add_test(tc_core, test_return_value);
  tcase_add_test(tc_core, test_copy_large_buffer);
  tcase_add_test(tc_core, test_copy_empty_src_n_one);
  tcase_add_test(tc_core, test_copy_partial_with_null_in_src);
  tcase_add_test(tc_core, test_copy_with_special_chars);
  tcase_add_test(tc_core, test_copy_unicode);
  tcase_add_test(tc_core, test_copy_partial_unicode);
  tcase_add_test(tc_core, test_copy_to_middle_of_dest);
  tcase_add_test(tc_core, test_copy_with_numbers);
  tcase_add_test(tc_core, test_copy_with_space);
  tcase_add_test(tc_core, test_copy_with_tab_and_newline);
  tcase_add_test(tc_core, test_copy_with_non_ascii);

  suite_add_tcase(s, tc_core);
  return s;
}