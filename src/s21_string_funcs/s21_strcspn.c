#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;

  while (str1[len] != '\0') {
    for (const char *s = str2; *s != '\0'; s++) {
      if (str1[len] == *s) {
        return len;
      }
    }
    len++;
  }
  return len;
}