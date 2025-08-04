#include "tests.h"

#include <check.h>
#include <stdlib.h>

int main(void) {
  SRunner *sr = srunner_create(handle_c_suite());
  srunner_add_suite(sr, handle_di_suite());
  srunner_add_suite(sr, handle_s_suite());
  srunner_add_suite(sr, handle_fF_suite());
  srunner_add_suite(sr, handle_xX_suite());
  srunner_add_suite(sr, handle_o_suite());
  srunner_add_suite(sr, handle_u_suite());
  srunner_add_suite(sr, handle_p_suite());
  srunner_add_suite(sr, handle_n_suite());
  srunner_add_suite(sr, handle_percent_suite());
  srunner_add_suite(sr, handle_eE_suite());
  srunner_add_suite(sr, handle_gG_suite());
  srunner_add_suite(sr, memchr_suite());
  srunner_add_suite(sr, memcmp_suite());
  srunner_add_suite(sr, memcpy_suite());
  srunner_add_suite(sr, memset_suite());
  srunner_add_suite(sr, strchr_suite());
  srunner_add_suite(sr, strcspn_suite());
  srunner_add_suite(sr, strerror_suite());
  srunner_add_suite(sr, strlen_suite());
  srunner_add_suite(sr, strncat_suite());
  srunner_add_suite(sr, strncmp_suite());
  srunner_add_suite(sr, strncpy_suite());
  srunner_add_suite(sr, strrchr_suite());
  srunner_add_suite(sr, strstr_suite());
  srunner_add_suite(sr, strtok_suite());
  srunner_add_suite(sr, strpbrk_suite());
  srunner_add_suite(sr, s21_sprintf_suite());
  srunner_add_suite(sr, s21_insert_suite());
  srunner_add_suite(sr, s21_to_lower_suite());
  srunner_add_suite(sr, s21_to_upper_suite());
  srunner_add_suite(sr, trim_suite());

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}