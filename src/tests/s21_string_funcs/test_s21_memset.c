#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_set_all_bytes) {
  char buf1[10], buf2[10];
  s21_memset(buf1, 'A', 10);
  memset(buf2, 'A', 10);
  ck_assert_mem_eq(buf1, buf2, 10);
}
END_TEST

START_TEST(test_set_partial) {
  char buf1[10] = "abcdefgh";
  char buf2[10] = "abcdefgh";
  s21_memset(buf1, 'C', 4);
  memset(buf2, 'C', 4);
  ck_assert_mem_eq(buf1, buf2, 10);
}
END_TEST

START_TEST(test_set_null_byte) {
  char buf1[5] = "abcd";
  char buf2[5] = "abcd";
  s21_memset(buf1, '\0', 4);
  memset(buf2, '\0', 4);
  ck_assert_mem_eq(buf1, buf2, 5);
}
END_TEST

START_TEST(test_set_large_buffer) {
  char buf1[1000], buf2[1000];
  s21_memset(buf1, 0x7F, 1000);
  memset(buf2, 0x7F, 1000);
  ck_assert_mem_eq(buf1, buf2, 1000);
}
END_TEST

START_TEST(test_set_one_byte) {
  char buf1[3] = "xy";
  char buf2[3] = "xy";
  s21_memset(buf1, 'Z', 1);
  memset(buf2, 'Z', 1);
  ck_assert_mem_eq(buf1, buf2, 3);
}
END_TEST

START_TEST(test_set_unsigned_char) {
  unsigned char buf1[4] = {1, 2, 3, 4};
  unsigned char buf2[4] = {1, 2, 3, 4};
  s21_memset(buf1, 255, 4);
  memset(buf2, 255, 4);
  ck_assert_mem_eq(buf1, buf2, 4);
}
END_TEST

START_TEST(test_set_negative_value) {
  char buf1[5] = "test";
  char buf2[5] = "test";
  s21_memset(buf1, -1, 4);
  memset(buf2, -1, 4);
  ck_assert_mem_eq(buf1, buf2, 5);
}
END_TEST

START_TEST(test_set_empty_string) {
  char buf1[1] = "";
  char buf2[1] = "";
  s21_memset(buf1, 'Q', 1);
  memset(buf2, 'Q', 1);
  ck_assert_mem_eq(buf1, buf2, 1);
}
END_TEST

START_TEST(test_return_value) {
  char buf[5] = "abcd";
  void *ret = s21_memset(buf, 'X', 4);
  ck_assert_ptr_eq(ret, buf);
}
END_TEST

START_TEST(test_set_full_buffer_to_zero) {
  char buf1[8] = "1234567";
  char buf2[8] = "1234567";
  s21_memset(buf1, 0, 8);
  memset(buf2, 0, 8);
  ck_assert_mem_eq(buf1, buf2, 8);
}
END_TEST

START_TEST(test_set_middle_of_buffer) {
  char buf1[10] = "abcdefgh";
  char buf2[10] = "abcdefgh";
  s21_memset(buf1 + 3, 'Z', 4);
  memset(buf2 + 3, 'Z', 4);
  ck_assert_mem_eq(buf1, buf2, 10);
}
END_TEST

START_TEST(test_set_large_partial) {
  char buf1[1000], buf2[1000];
  memset(buf1, 'A', 1000);
  memset(buf2, 'A', 1000);
  s21_memset(buf1 + 500, 'B', 200);
  memset(buf2 + 500, 'B', 200);
  ck_assert_mem_eq(buf1, buf2, 1000);
}
END_TEST

START_TEST(test_set_struct) {
  struct {
    int a;
    double b;
    char c;
  } s1 = {1, 2.0, 'a'};
  struct {
    int a;
    double b;
    char c;
  } s2 = {1, 2.0, 'a'};
  s21_memset(&s1, 0, sizeof(s1));
  memset(&s2, 0, sizeof(s2));
  ck_assert_mem_eq(&s1, &s2, sizeof(s1));
}
END_TEST

START_TEST(test_set_value_greater_than_uchar) {
  char buf1[4] = {0, 0, 0, 0};
  char buf2[4] = {0, 0, 0, 0};
  s21_memset(buf1, 257, 4);
  memset(buf2, 257, 4);
  ck_assert_mem_eq(buf1, buf2, 4);
}
END_TEST

START_TEST(test_set_value_less_than_zero) {
  char buf1[4] = {0, 0, 0, 0};
  char buf2[4] = {0, 0, 0, 0};
  s21_memset(buf1, -255, 4);
  memset(buf2, -255, 4);
  ck_assert_mem_eq(buf1, buf2, 4);
}
END_TEST

START_TEST(test_set_one_byte_at_end) {
  char buf1[5] = "abcd";
  char buf2[5] = "abcd";
  s21_memset(buf1 + 4, 'Q', 1);
  memset(buf2 + 4, 'Q', 1);
  ck_assert_mem_eq(buf1, buf2, 5);
}
END_TEST

Suite *memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memset");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_set_all_bytes);
  tcase_add_test(tc_core, test_set_partial);
  tcase_add_test(tc_core, test_set_null_byte);
  tcase_add_test(tc_core, test_set_large_buffer);
  tcase_add_test(tc_core, test_set_one_byte);
  tcase_add_test(tc_core, test_set_unsigned_char);
  tcase_add_test(tc_core, test_set_negative_value);
  tcase_add_test(tc_core, test_set_empty_string);
  tcase_add_test(tc_core, test_return_value);
  tcase_add_test(tc_core, test_set_full_buffer_to_zero);
  tcase_add_test(tc_core, test_set_middle_of_buffer);
  tcase_add_test(tc_core, test_set_large_partial);
  tcase_add_test(tc_core, test_set_struct);
  tcase_add_test(tc_core, test_set_value_greater_than_uchar);
  tcase_add_test(tc_core, test_set_value_less_than_zero);
  tcase_add_test(tc_core, test_set_one_byte_at_end);

  suite_add_tcase(s, tc_core);
  return s;
}