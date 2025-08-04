#include <stdlib.h>

#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = S21_NULL;

  if (src != NULL) {
    const char *chars_to_trim = trim_chars;

    s21_size_t src_length = 0;
    while (src[src_length] != '\0') {
      src_length++;
    }

    if (src_length == 0) {
      char *empty_result = (char *)malloc(1);
      if (empty_result != NULL) {
        empty_result[0] = '\0';
        result = (void *)empty_result;
      }
    } else {
      s21_size_t start_pos = 0;
      while (start_pos < src_length) {
        int is_trim_char = 0;
        for (s21_size_t i = 0; chars_to_trim[i] != '\0'; i++) {
          if (src[start_pos] == chars_to_trim[i]) {
            is_trim_char = 1;
            break;
          }
        }
        if (!is_trim_char) {
          break;
        }
        start_pos++;
      }

      int end_pos = (int)src_length - 1;
      while (end_pos >= (int)start_pos) {
        int is_trim_char = 0;
        for (s21_size_t i = 0; chars_to_trim[i] != '\0'; i++) {
          if (src[end_pos] == chars_to_trim[i]) {
            is_trim_char = 1;
            break;
          }
        }
        if (!is_trim_char) {
          break;
        }
        end_pos--;
      }

      s21_size_t result_length = 0;
      if (end_pos >= (int)start_pos) {
        result_length = (s21_size_t)(end_pos - start_pos + 1);
      }

      char *trimmed_result = (char *)malloc(result_length + 1);

      if (trimmed_result != NULL) {
        for (s21_size_t i = 0; i < result_length; i++) {
          trimmed_result[i] = src[start_pos + i];
        }
        trimmed_result[result_length] = '\0';
        result = (void *)trimmed_result;
      }
    }
  }

  return result;
}