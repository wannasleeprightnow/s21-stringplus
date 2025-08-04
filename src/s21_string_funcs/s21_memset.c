#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *string = (unsigned char *)str;
  unsigned char uc = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    string[i] = uc;
  }
  return str;
}