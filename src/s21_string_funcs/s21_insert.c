#include <stdlib.h>

#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *total_string = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t src_len = 0;
    while (src[src_len] != '\0') {
      src_len++;
    }
    s21_size_t str_len = 0;
    while (str[str_len] != '\0') {
      str_len++;
    }

    if (start_index <= src_len) {
      s21_size_t total_len = src_len + str_len;
      total_string = (char *)malloc((total_len + 1) * sizeof(char));
      if (total_string != S21_NULL) {
        for (s21_size_t i = 0; i < start_index; i++) {
          total_string[i] = src[i];
        }
        for (s21_size_t i = 0; i < str_len; i++) {
          total_string[start_index + i] = str[i];
        }
        for (s21_size_t i = 0; i < src_len - start_index; i++) {
          total_string[start_index + str_len + i] = src[start_index + i];
        }
        total_string[total_len] = '\0';
      }
    }
  }

  return (void *)total_string;
}