#include <check.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(strtok_basic) {
  char str1[] = "a,b,c";
  char str2[] = "a,b,c";
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, ",");
    tok2 = strtok(NULL, ",");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_empty_str) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_ptr_eq(s21_strtok(str1, ","), strtok(str2, ","));
}
END_TEST

START_TEST(strtok_empty_delim) {
  char str1[] = "abc";
  char str2[] = "abc";
  char *tok1 = s21_strtok(str1, "");
  char *tok2 = strtok(str2, "");
  if (tok2 != NULL) {
    ck_assert_ptr_ne(tok1, NULL);
    ck_assert_str_eq(tok1, tok2);
  } else {
    ck_assert_ptr_eq(tok1, NULL);
  }
}
END_TEST

START_TEST(strtok_only_delim) {
  char str1[] = ",,,";
  char str2[] = ",,,";
  ck_assert_ptr_eq(s21_strtok(str1, ","), strtok(str2, ","));
}
END_TEST

START_TEST(strtok_no_delim) {
  char str1[] = "abc";
  char str2[] = "abc";
  ck_assert_str_eq(s21_strtok(str1, ","), strtok(str2, ","));
}
END_TEST

START_TEST(strtok_multiple_delim) {
  char str1[] = "a,b;c";
  char str2[] = "a,b;c";
  char *tok1 = s21_strtok(str1, ",;");
  char *tok2 = strtok(str2, ",;");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, ",;");
    tok2 = strtok(NULL, ",;");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_leading_delim) {
  char str1[] = ",a,b";
  char str2[] = ",a,b";
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, ",");
    tok2 = strtok(NULL, ",");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_trailing_delim) {
  char str1[] = "a,b,";
  char str2[] = "a,b,";
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, ",");
    tok2 = strtok(NULL, ",");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_unicode) {
  char str1[] = "абв,где";
  char str2[] = "абв,где";
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, ",");
    tok2 = strtok(NULL, ",");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_special_chars) {
  char str1[] = "a!@#b!@#c";
  char str2[] = "a!@#b!@#c";
  char *tok1 = s21_strtok(str1, "!@#");
  char *tok2 = strtok(str2, "!@#");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, "!@#");
    tok2 = strtok(NULL, "!@#");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_consecutive_delims) {
  char str1[] = "a,,b,,,c";
  char str2[] = "a,,b,,,c";
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, ",");
    tok2 = strtok(NULL, ",");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_all_delims) {
  char str1[] = ",,,";
  char str2[] = ",,,";
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_no_tokens) {
  char str1[] = ",,,";
  char str2[] = ",,,";
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_single_char) {
  char str1[] = "a";
  char str2[] = "a";
  ck_assert_str_eq(s21_strtok(str1, ","), strtok(str2, ","));
}
END_TEST

START_TEST(strtok_delim_is_space) {
  char str1[] = "a b c";
  char str2[] = "a b c";
  char *tok1 = s21_strtok(str1, " ");
  char *tok2 = strtok(str2, " ");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, " ");
    tok2 = strtok(NULL, " ");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_delim_is_newline) {
  char str1[] = "a\nb\nc";
  char str2[] = "a\nb\nc";
  char *tok1 = s21_strtok(str1, "\n");
  char *tok2 = strtok(str2, "\n");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, "\n");
    tok2 = strtok(NULL, "\n");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_delim_is_tab) {
  char str1[] = "a\tb\tc";
  char str2[] = "a\tb\tc";
  char *tok1 = s21_strtok(str1, "\t");
  char *tok2 = strtok(str2, "\t");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, "\t");
    tok2 = strtok(NULL, "\t");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_delim_at_start_and_end) {
  char str1[] = ",a,b,";
  char str2[] = ",a,b,";
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, ",");
    tok2 = strtok(NULL, ",");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_long_string) {
  char str1[100] = {0};
  char str2[100] = {0};
  memset(str1, 'a', 99);
  memset(str2, 'a', 99);
  str1[10] = ',';
  str2[10] = ',';
  char *tok1 = s21_strtok(str1, ",");
  char *tok2 = strtok(str2, ",");
  while (tok1 && tok2) {
    ck_assert_str_eq(tok1, tok2);
    tok1 = s21_strtok(NULL, ",");
    tok2 = strtok(NULL, ",");
  }
  ck_assert_ptr_eq(tok1, tok2);
}
END_TEST

START_TEST(strtok_delim_not_in_string) {
  char str1[] = "abcdef";
  char str2[] = "abcdef";
  ck_assert_str_eq(s21_strtok(str1, "x"), strtok(str2, "x"));
}
END_TEST

START_TEST(strtok_multiple_calls_after_end) {
  char str1[] = "a,b";
  char str2[] = "a,b";
  s21_strtok(str1, ",");
  strtok(str2, ",");
  s21_strtok(NULL, ",");
  strtok(NULL, ",");
  ck_assert_ptr_eq(s21_strtok(NULL, ","), strtok(NULL, ","));
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, strtok_basic);
  tcase_add_test(tc, strtok_empty_str);
  tcase_add_test(tc, strtok_empty_delim);
  tcase_add_test(tc, strtok_only_delim);
  tcase_add_test(tc, strtok_no_delim);
  tcase_add_test(tc, strtok_multiple_delim);
  tcase_add_test(tc, strtok_leading_delim);
  tcase_add_test(tc, strtok_trailing_delim);
  tcase_add_test(tc, strtok_unicode);
  tcase_add_test(tc, strtok_special_chars);
  tcase_add_test(tc, strtok_consecutive_delims);
  tcase_add_test(tc, strtok_all_delims);
  tcase_add_test(tc, strtok_no_tokens);
  tcase_add_test(tc, strtok_single_char);
  tcase_add_test(tc, strtok_delim_is_space);
  tcase_add_test(tc, strtok_delim_is_newline);
  tcase_add_test(tc, strtok_delim_is_tab);
  tcase_add_test(tc, strtok_delim_at_start_and_end);
  tcase_add_test(tc, strtok_long_string);
  tcase_add_test(tc, strtok_delim_not_in_string);
  tcase_add_test(tc, strtok_multiple_calls_after_end);
  suite_add_tcase(s, tc);
  return s;
}