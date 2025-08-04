#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"
#include "../tests.h"

#define BUFF_SIZE 512

START_TEST(test_s21_sprintf_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%c", 'A');
  int res2 = sprintf(str2, "%c", 'A');

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%s", "Hello, world!");
  int res2 = sprintf(str2, "%s", "Hello, world!");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_percent) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%%");
  int res2 = sprintf(str2, "%%");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%d", 12345);
  int res2 = sprintf(str2, "%d", 12345);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_negative_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%d", -12345);
  int res2 = sprintf(str2, "%d", -12345);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%u", 12345);
  int res2 = sprintf(str2, "%u", 12345);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%x", 0xABC);
  int res2 = sprintf(str2, "%x", 0xABC);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%X", 0xABC);
  int res2 = sprintf(str2, "%X", 0xABC);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%o", 0755);
  int res2 = sprintf(str2, "%o", 0755);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_pointer) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int x = 42;

  int res1 = s21_sprintf(str1, "%p", &x);
  int res2 = sprintf(str2, "%p", &x);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_null_pointer) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%p", NULL);
  int res2 = sprintf(str2, "%p", NULL);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%f", 123.456);
  int res2 = sprintf(str2, "%f", 123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_negative_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%f", -123.456);
  int res2 = sprintf(str2, "%f", -123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_exp_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%e", 123.456);
  int res2 = sprintf(str2, "%e", 123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_exp_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%E", 123.456);
  int res2 = sprintf(str2, "%E", 123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_g_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%g", 123.456);
  int res2 = sprintf(str2, "%g", 123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_g_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%G", 123.456);
  int res2 = sprintf(str2, "%G", 123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_n) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1, n2;

  s21_sprintf(str1, "Hello%nWorld", &n1);
  sprintf(str2, "Hello%nWorld", &n2);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_sprintf_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%10d", 123);
  int res2 = sprintf(str2, "%10d", 123);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_left_align) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%-10d", 123);
  int res2 = sprintf(str2, "%-10d", 123);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_zero_pad) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%010d", 123);
  int res2 = sprintf(str2, "%010d", 123);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%.5d", 123);
  int res2 = sprintf(str2, "%.5d", 123);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_precision_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%.2f", 123.456);
  int res2 = sprintf(str2, "%.2f", 123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_precision_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%.5s", "Hello, world!");
  int res2 = sprintf(str2, "%.5s", "Hello, world!");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_plus_flag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%+d", 123);
  int res2 = sprintf(str2, "%+d", 123);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_space_flag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "% d", 123);
  int res2 = sprintf(str2, "% d", 123);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hash_flag_hex) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%#x", 0xABC);
  int res2 = sprintf(str2, "%#x", 0xABC);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hash_flag_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%#o", 0755);
  int res2 = sprintf(str2, "%#o", 0755);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%ld", 123456789L);
  int res2 = sprintf(str2, "%ld", 123456789L);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_long_unsigned) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%lu", 123456789UL);
  int res2 = sprintf(str2, "%lu", 123456789UL);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%hd", (short)12345);
  int res2 = sprintf(str2, "%hd", (short)12345);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_long_double) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%Lf", 123.456L);
  int res2 = sprintf(str2, "%Lf", 123.456L);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_mixed) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "Char: %c, Int: %d, Str: %s", 'A', 123, "test");
  int res2 = sprintf(str2, "Char: %c, Int: %d, Str: %s", 'A', 123, "test");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_int_max) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%d", INT_MAX);
  int res2 = sprintf(str2, "%d", INT_MAX);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_int_min) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%d", INT_MIN);
  int res2 = sprintf(str2, "%d", INT_MIN);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_uint_max) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%u", UINT_MAX);
  int res2 = sprintf(str2, "%u", UINT_MAX);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_float_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%f", 1.23456e20);
  int res2 = sprintf(str2, "%f", 1.23456e20);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_float_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%f", 1.23456e-20);
  int res2 = sprintf(str2, "%f", 1.23456e-20);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_inf) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%f", INFINITY);
  int res2 = sprintf(str2, "%f", INFINITY);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_nan) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%f", NAN);
  int res2 = sprintf(str2, "%f", NAN);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_zero_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%.0d", 0);
  int res2 = sprintf(str2, "%.0d", 0);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_zero_precision_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%.0f", 123.456);
  int res2 = sprintf(str2, "%.0f", 123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_star_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%*d", 10, 123);
  int res2 = sprintf(str2, "%*d", 10, 123);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_star_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%.*f", 2, 123.456);
  int res2 = sprintf(str2, "%.*f", 2, 123.456);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_literal_percent) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "100%%");
  int res2 = sprintf(str2, "100%%");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_multiple_formats) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%d %f %s", 123, 45.67, "test");
  int res2 = sprintf(str2, "%d %f %s", 123, 45.67, "test");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_no_format) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "Just a string");
  int res2 = sprintf(str2, "Just a string");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%x", 0);
  int res2 = sprintf(str2, "%x", 0);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%o", 0);
  int res2 = sprintf(str2, "%o", 0);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_empty_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%s", "");
  int res2 = sprintf(str2, "%s", "");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_multiple_chars) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%c %c %c", 'a', 'b', 'c');
  int res2 = sprintf(str2, "%c %c %c", 'a', 'b', 'c');

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_negative_zero_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  double minus_zero = -0.0;
  int res1 = s21_sprintf(str1, "%f", minus_zero);
  int res2 = sprintf(str2, "%f", minus_zero);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_large_width_and_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%20.10f", 123.456789);
  int res2 = sprintf(str2, "%20.10f", 123.456789);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_zero_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%0d", 42);
  int res2 = sprintf(str2, "%0d", 42);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_negative_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%*d", -10, 42);
  int res2 = sprintf(str2, "%*d", -10, 42);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_string_with_null_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char s[] = "abc\0def";

  int res1 = s21_sprintf(str1, "%s", s);
  int res2 = sprintf(str2, "%s", s);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_zero_pad_and_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%#08x", 0x1A);
  int res2 = sprintf(str2, "%#08x", 0x1A);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_octal_with_zero_pad_and_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%#08o", 0123);
  int res2 = sprintf(str2, "%#08o", 0123);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_multiple_percent_signs) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%%%%%%");
  int res2 = sprintf(str2, "%%%%%%");

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_long_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  long long int val = 9223372036854775807LL;
  int res1 = s21_sprintf(str1, "%lld", val);
  int res2 = sprintf(str2, "%lld", val);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_short_unsigned) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  unsigned short val = 65535;
  int res1 = s21_sprintf(str1, "%hu", val);
  int res2 = sprintf(str2, "%hu", val);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_pointer_null) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int res1 = s21_sprintf(str1, "%p", NULL);
  int res2 = sprintf(str2, "%p", NULL);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_upper_zero) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%X", 0);
  int res2 = sprintf(str2, "%X", 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_width) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%8x", 255);
  int res2 = sprintf(str2, "%8x", 255);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_zero_pad) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%08x", 255);
  int res2 = sprintf(str2, "%08x", 255);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_hash) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%#x", 255);
  int res2 = sprintf(str2, "%#x", 255);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_hash_zero) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%#x", 0);
  int res2 = sprintf(str2, "%#x", 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_octal_with_hash) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%#o", 10);
  int res2 = sprintf(str2, "%#o", 10);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_octal_with_hash_zero) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%#o", 0);
  int res2 = sprintf(str2, "%#o", 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_with_precision) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%.5x", 31);
  int res2 = sprintf(str2, "%.5x", 31);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_octal_with_precision) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%.5o", 31);
  int res2 = sprintf(str2, "%.5o", 31);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_negative) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%x", -1);
  int res2 = sprintf(str2, "%x", -1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_octal_negative) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%o", -1);
  int res2 = sprintf(str2, "%o", -1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_hex_mixed_flags) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%#08x", 42);
  int res2 = sprintf(str2, "%#08x", 42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_octal_mixed_flags) {
  char str1[BUFF_SIZE], str2[BUFF_SIZE];
  int res1 = s21_sprintf(str1, "%#08o", 42);
  int res2 = sprintf(str2, "%#08o", 42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_rounding_up) {
  char str1[512];
  char str2[512];
  long double value = 123.456789L;

  int res1 = s21_sprintf(str1, "%.2Lf", value);
  int res2 = sprintf(str2, "%.2Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_zero_precision) {
  char str1[512];
  char str2[512];
  long double value = 123.5L;

  int res1 = s21_sprintf(str1, "%.0Lf", value);
  int res2 = sprintf(str2, "%.0Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_high_precision) {
  char str1[512];
  char str2[512];
  long double value = 0.123456789123456789L;

  int res1 = s21_sprintf(str1, "%.15Lf", value);
  int res2 = sprintf(str2, "%.15Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_negative) {
  char str1[512];
  char str2[512];
  long double value = -123.456L;

  int res1 = s21_sprintf(str1, "%Lf", value);
  int res2 = sprintf(str2, "%Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_plus_flag) {
  char str1[512];
  char str2[512];
  long double value = 123.456L;

  int res1 = s21_sprintf(str1, "%+Lf", value);
  int res2 = sprintf(str2, "%+Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_zero_padding) {
  char str1[512];
  char str2[512];
  long double value = -12.34L;

  int res1 = s21_sprintf(str1, "%020.2Lf", value);
  int res2 = sprintf(str2, "%020.2Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_zero) {
  char str1[512];
  char str2[512];
  long double value = 0.0L;

  int res1 = s21_sprintf(str1, "%Lf", value);
  int res2 = sprintf(str2, "%Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_integer_value) {
  char str1[512];
  char str2[512];
  long double value = 987.0L;

  int res1 = s21_sprintf(str1, "%Lf", value);
  int res2 = sprintf(str2, "%Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_less_than_one) {
  char str1[512];
  char str2[512];
  long double value = 0.123L;

  int res1 = s21_sprintf(str1, "%Lf", value);
  int res2 = sprintf(str2, "%Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_inf) {
  char str1[512];
  char str2[512];
  long double value = INFINITY;

  int res1 = s21_sprintf(str1, "%Lf", value);
  int res2 = sprintf(str2, "%Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_Lf_nan) {
  char str1[512];
  char str2[512];
  long double value = NAN;

  int res1 = s21_sprintf(str1, "%Lf", value);
  int res2 = sprintf(str2, "%Lf", value);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_s21_sprintf_char);
  tcase_add_test(tc, test_s21_sprintf_string);
  tcase_add_test(tc, test_s21_sprintf_percent);
  tcase_add_test(tc, test_s21_sprintf_int);
  tcase_add_test(tc, test_s21_sprintf_negative_int);
  tcase_add_test(tc, test_s21_sprintf_unsigned);
  tcase_add_test(tc, test_s21_sprintf_hex_lower);
  tcase_add_test(tc, test_s21_sprintf_hex_upper);
  tcase_add_test(tc, test_s21_sprintf_octal);
  tcase_add_test(tc, test_s21_sprintf_pointer);
  tcase_add_test(tc, test_s21_sprintf_null_pointer);
  tcase_add_test(tc, test_s21_sprintf_float);
  tcase_add_test(tc, test_s21_sprintf_negative_float);
  tcase_add_test(tc, test_s21_sprintf_exp_lower);
  tcase_add_test(tc, test_s21_sprintf_exp_upper);
  tcase_add_test(tc, test_s21_sprintf_g_lower);
  tcase_add_test(tc, test_s21_sprintf_g_upper);
  tcase_add_test(tc, test_s21_sprintf_n);
  tcase_add_test(tc, test_s21_sprintf_width);
  tcase_add_test(tc, test_s21_sprintf_left_align);
  tcase_add_test(tc, test_s21_sprintf_zero_pad);
  tcase_add_test(tc, test_s21_sprintf_precision_int);
  tcase_add_test(tc, test_s21_sprintf_precision_float);
  tcase_add_test(tc, test_s21_sprintf_precision_string);
  tcase_add_test(tc, test_s21_sprintf_plus_flag);
  tcase_add_test(tc, test_s21_sprintf_space_flag);
  tcase_add_test(tc, test_s21_sprintf_hash_flag_hex);
  tcase_add_test(tc, test_s21_sprintf_hash_flag_octal);
  tcase_add_test(tc, test_s21_sprintf_long_int);
  tcase_add_test(tc, test_s21_sprintf_long_unsigned);
  tcase_add_test(tc, test_s21_sprintf_short_int);
  tcase_add_test(tc, test_s21_sprintf_long_double);
  tcase_add_test(tc, test_s21_sprintf_mixed);
  tcase_add_test(tc, test_s21_sprintf_int_max);
  tcase_add_test(tc, test_s21_sprintf_int_min);
  tcase_add_test(tc, test_s21_sprintf_uint_max);
  tcase_add_test(tc, test_s21_sprintf_float_large);
  tcase_add_test(tc, test_s21_sprintf_float_small);
  tcase_add_test(tc, test_s21_sprintf_inf);
  tcase_add_test(tc, test_s21_sprintf_nan);
  tcase_add_test(tc, test_s21_sprintf_zero_precision_int);
  tcase_add_test(tc, test_s21_sprintf_zero_precision_float);
  tcase_add_test(tc, test_s21_sprintf_star_width);
  tcase_add_test(tc, test_s21_sprintf_star_precision);
  tcase_add_test(tc, test_s21_sprintf_literal_percent);
  tcase_add_test(tc, test_s21_sprintf_multiple_formats);
  tcase_add_test(tc, test_s21_sprintf_no_format);
  tcase_add_test(tc, test_s21_sprintf_hex_zero);
  tcase_add_test(tc, test_s21_sprintf_octal_zero);
  tcase_add_test(tc, test_s21_sprintf_empty_string);
  tcase_add_test(tc, test_s21_sprintf_multiple_chars);
  tcase_add_test(tc, test_s21_sprintf_negative_zero_float);
  tcase_add_test(tc, test_s21_sprintf_large_width_and_precision);
  tcase_add_test(tc, test_s21_sprintf_zero_width);
  tcase_add_test(tc, test_s21_sprintf_string_with_null_char);
  tcase_add_test(tc, test_s21_sprintf_hex_with_zero_pad_and_hash);
  tcase_add_test(tc, test_s21_sprintf_octal_with_zero_pad_and_hash);
  tcase_add_test(tc, test_s21_sprintf_octal_with_zero_pad_and_hash);
  tcase_add_test(tc, test_s21_sprintf_multiple_percent_signs);
  tcase_add_test(tc, test_s21_sprintf_long_long_int);
  tcase_add_test(tc, test_s21_sprintf_short_unsigned);
  tcase_add_test(tc, test_s21_sprintf_pointer_null);
  tcase_add_test(tc, test_s21_sprintf_negative_width);
  tcase_add_test(tc, test_s21_sprintf_hex_upper_zero);
  tcase_add_test(tc, test_s21_sprintf_hex_with_width);
  tcase_add_test(tc, test_s21_sprintf_hex_with_zero_pad);
  tcase_add_test(tc, test_s21_sprintf_hex_with_hash);
  tcase_add_test(tc, test_s21_sprintf_hex_with_hash_zero);
  tcase_add_test(tc, test_s21_sprintf_octal_with_hash);
  tcase_add_test(tc, test_s21_sprintf_octal_with_hash_zero);
  tcase_add_test(tc, test_s21_sprintf_hex_with_precision);
  tcase_add_test(tc, test_s21_sprintf_hex_upper);
  tcase_add_test(tc, test_s21_sprintf_hex_mixed_flags);
  tcase_add_test(tc, test_s21_sprintf_octal_mixed_flags);
  tcase_add_test(tc, test_s21_sprintf_octal_with_precision);
  tcase_add_test(tc, test_s21_sprintf_octal_negative);
  tcase_add_test(tc, test_s21_sprintf_hex_upper);
  tcase_add_test(tc, test_s21_sprintf_hex_negative);
  tcase_add_test(tc, test_s21_sprintf_Lf_rounding_up);
  tcase_add_test(tc, test_s21_sprintf_Lf_zero_precision);
  tcase_add_test(tc, test_s21_sprintf_Lf_high_precision);
  tcase_add_test(tc, test_s21_sprintf_Lf_negative);
  tcase_add_test(tc, test_s21_sprintf_Lf_plus_flag);
  tcase_add_test(tc, test_s21_sprintf_Lf_zero_padding);
  tcase_add_test(tc, test_s21_sprintf_Lf_zero);
  tcase_add_test(tc, test_s21_sprintf_Lf_integer_value);
  tcase_add_test(tc, test_s21_sprintf_Lf_less_than_one);
  tcase_add_test(tc, test_s21_sprintf_Lf_inf);
  tcase_add_test(tc, test_s21_sprintf_Lf_nan);

  suite_add_tcase(s, tc);
  return s;
}
