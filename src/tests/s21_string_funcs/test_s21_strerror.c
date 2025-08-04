#include <check.h>
#include <errno.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(strerror_zero) { ck_assert_str_eq(s21_strerror(0), strerror(0)); }
END_TEST
START_TEST(strerror_einval) {
  ck_assert_str_eq(s21_strerror(EINVAL), strerror(EINVAL));
}
END_TEST
START_TEST(strerror_enoent) {
  ck_assert_str_eq(s21_strerror(ENOENT), strerror(ENOENT));
}
END_TEST
START_TEST(strerror_erange) {
  ck_assert_str_eq(s21_strerror(ERANGE), strerror(ERANGE));
}
END_TEST
START_TEST(strerror_eperm) {
  ck_assert_str_eq(s21_strerror(EPERM), strerror(EPERM));
}
END_TEST
START_TEST(strerror_eio) { ck_assert_str_eq(s21_strerror(EIO), strerror(EIO)); }
END_TEST
START_TEST(strerror_e2big) {
  ck_assert_str_eq(s21_strerror(E2BIG), strerror(E2BIG));
}
END_TEST
START_TEST(strerror_negative) {
  ck_assert_str_eq(s21_strerror(-1), strerror(-1));
}
END_TEST
START_TEST(strerror_large) {
  ck_assert_str_eq(s21_strerror(9999), strerror(9999));
}
END_TEST
START_TEST(strerror_boundary) {
  ck_assert_str_eq(s21_strerror(255), strerror(255));
}
END_TEST
START_TEST(strerror_eacces) {
  ck_assert_str_eq(s21_strerror(EACCES), strerror(EACCES));
}
END_TEST

START_TEST(strerror_eagain) {
  ck_assert_str_eq(s21_strerror(EAGAIN), strerror(EAGAIN));
}
END_TEST

START_TEST(strerror_eexist) {
  ck_assert_str_eq(s21_strerror(EEXIST), strerror(EEXIST));
}
END_TEST

START_TEST(strerror_efault) {
  ck_assert_str_eq(s21_strerror(EFAULT), strerror(EFAULT));
}
END_TEST

START_TEST(strerror_eintr) {
  ck_assert_str_eq(s21_strerror(EINTR), strerror(EINTR));
}
END_TEST

START_TEST(strerror_emfile) {
  ck_assert_str_eq(s21_strerror(EMFILE), strerror(EMFILE));
}
END_TEST

START_TEST(strerror_eisdir) {
  ck_assert_str_eq(s21_strerror(EISDIR), strerror(EISDIR));
}
END_TEST

START_TEST(strerror_eacces_plus_one) {
  ck_assert_str_eq(s21_strerror(EACCES + 1), strerror(EACCES + 1));
}
END_TEST

START_TEST(strerror_zero_minus_one) {
  ck_assert_str_eq(s21_strerror(0 - 1), strerror(0 - 1));
}
END_TEST

START_TEST(strerror_max_int) {
  ck_assert_str_eq(s21_strerror(2147483647), strerror(2147483647));
}
END_TEST

START_TEST(strerror_min_int) {
  ck_assert_str_eq(s21_strerror(-2147483647 - 1), strerror(-2147483647 - 1));
}
END_TEST

START_TEST(strerror_eperm_plus_100) {
  ck_assert_str_eq(s21_strerror(EPERM + 100), strerror(EPERM + 100));
}
END_TEST

START_TEST(strerror_eio_minus_100) {
  ck_assert_str_eq(s21_strerror(EIO - 100), strerror(EIO - 100));
}
END_TEST

START_TEST(strerror_zero_again) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, strerror_zero);
  tcase_add_test(tc, strerror_einval);
  tcase_add_test(tc, strerror_enoent);
  tcase_add_test(tc, strerror_erange);
  tcase_add_test(tc, strerror_eperm);
  tcase_add_test(tc, strerror_eio);
  tcase_add_test(tc, strerror_e2big);
  tcase_add_test(tc, strerror_negative);
  tcase_add_test(tc, strerror_large);
  tcase_add_test(tc, strerror_boundary);
  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_eacces);
  tcase_add_test(tc, strerror_eagain);
  tcase_add_test(tc, strerror_eexist);
  tcase_add_test(tc, strerror_efault);
  tcase_add_test(tc, strerror_eintr);
  tcase_add_test(tc, strerror_emfile);
  tcase_add_test(tc, strerror_eisdir);
  tcase_add_test(tc, strerror_eacces_plus_one);
  tcase_add_test(tc, strerror_zero_minus_one);
  tcase_add_test(tc, strerror_max_int);
  tcase_add_test(tc, strerror_min_int);
  tcase_add_test(tc, strerror_eperm_plus_100);
  tcase_add_test(tc, strerror_eio_minus_100);
  tcase_add_test(tc, strerror_zero_again);
  return s;
}