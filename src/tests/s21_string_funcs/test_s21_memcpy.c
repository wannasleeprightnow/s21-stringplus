#include <assert.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_copy_simple_string) {
  char src[] = "hello";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_memcpy(dest1, src, 6);
  memcpy(dest2, src, 6);
  ck_assert_mem_eq(dest1, dest2, 6);
}
END_TEST

START_TEST(test_copy_zero_bytes) {
  char src[] = "hello";
  char dest1[10] = "abc";
  char dest2[10] = "abc";
  s21_memcpy(dest1, src, 0);
  memcpy(dest2, src, 0);
  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(test_copy_with_null_bytes) {
  char src[] = "ab\0cd";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_memcpy(dest1, src, 5);
  memcpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_copy_partial) {
  char src[] = "abcdef";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_memcpy(dest1, src, 3);
  memcpy(dest2, src, 3);
  ck_assert_mem_eq(dest1, dest2, 3);
}
END_TEST

START_TEST(test_copy_empty_src) {
  char src[] = "";
  char dest1[5] = "1234";
  char dest2[5] = "1234";
  s21_memcpy(dest1, src, 1);
  memcpy(dest2, src, 1);
  ck_assert_mem_eq(dest1, dest2, 1);
}
END_TEST

START_TEST(test_copy_large_buffer) {
  char src[1000];
  char dest1[1000];
  char dest2[1000];
  for (int i = 0; i < 1000; i++) src[i] = (char)(i % 256);
  s21_memcpy(dest1, src, 1000);
  memcpy(dest2, src, 1000);
  ck_assert_mem_eq(dest1, dest2, 1000);
}
END_TEST

START_TEST(test_copy_to_self) {
  char buf[10] = "abcdefghi";
  s21_memcpy(buf, buf, 10);
  ck_assert_mem_eq(buf, "abcdefghi", 10);
}
END_TEST

START_TEST(test_copy_one_byte) {
  char src[] = "abc";
  char dest1[] = "xyz";
  char dest2[] = "xyz";
  s21_memcpy(dest1, src, 1);
  memcpy(dest2, src, 1);
  ck_assert_mem_eq(dest1, dest2, 3);
}
END_TEST

START_TEST(test_copy_unsigned) {
  unsigned char src[] = {0xFF, 0x00, 0x7F};
  unsigned char dest1[3] = {0};
  unsigned char dest2[3] = {0};
  s21_memcpy(dest1, src, 3);
  memcpy(dest2, src, 3);
  ck_assert_mem_eq(dest1, dest2, 3);
}
END_TEST

START_TEST(test_copy_all_zeros) {
  char src[10] = {0};
  char dest1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  char dest2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_memcpy(dest1, src, 10);
  memcpy(dest2, src, 10);
  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(test_copy_large_partial) {
  char src[1000];
  char dest1[1000];
  char dest2[1000];
  for (int i = 0; i < 1000; i++) src[i] = (char)(i % 256);
  memset(dest1, 0, 1000);
  memset(dest2, 0, 1000);
  s21_memcpy(dest1, src, 500);
  memcpy(dest2, src, 500);
  ck_assert_mem_eq(dest1, dest2, 1000);
}
END_TEST

START_TEST(test_copy_one_byte_to_middle) {
  char src[] = "abc";
  char dest1[] = "xyz";
  char dest2[] = "xyz";
  s21_memcpy(dest1 + 1, src + 2, 1);
  memcpy(dest2 + 1, src + 2, 1);
  ck_assert_mem_eq(dest1, dest2, 3);
}
END_TEST

START_TEST(test_copy_large_unsigned) {
  unsigned char src[256];
  unsigned char dest1[256] = {0};
  unsigned char dest2[256] = {0};
  for (int i = 0; i < 256; i++) src[i] = (unsigned char)i;
  s21_memcpy(dest1, src, 256);
  memcpy(dest2, src, 256);
  ck_assert_mem_eq(dest1, dest2, 256);
}
END_TEST

START_TEST(test_copy_struct) {
  struct {
    int a;
    double b;
    char c;
  } src = {42, 3.14, 'x'};
  struct {
    int a;
    double b;
    char c;
  } dest1 = {0};
  struct {
    int a;
    double b;
    char c;
  } dest2 = {0};
  s21_memcpy(&dest1, &src, sizeof(src));
  memcpy(&dest2, &src, sizeof(src));
  ck_assert_mem_eq(&dest1, &dest2, sizeof(src));
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memcpy");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_copy_simple_string);
  tcase_add_test(tc_core, test_copy_zero_bytes);
  tcase_add_test(tc_core, test_copy_with_null_bytes);
  tcase_add_test(tc_core, test_copy_partial);
  tcase_add_test(tc_core, test_copy_empty_src);
  tcase_add_test(tc_core, test_copy_large_buffer);
  tcase_add_test(tc_core, test_copy_to_self);
  tcase_add_test(tc_core, test_copy_one_byte);
  tcase_add_test(tc_core, test_copy_unsigned);
  tcase_add_test(tc_core, test_copy_all_zeros);
  tcase_add_test(tc_core, test_copy_large_partial);
  tcase_add_test(tc_core, test_copy_one_byte_to_middle);
  tcase_add_test(tc_core, test_copy_large_unsigned);
  tcase_add_test(tc_core, test_copy_struct);

  suite_add_tcase(s, tc_core);
  return s;
}