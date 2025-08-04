#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  for (; *str1 != '\0'; str1++) {
    const char *p = str2;
    for (; *p != '\0'; p++) {
      if (*str1 == *p) return (char *)str1;
    }
  }

  return S21_NULL;
}