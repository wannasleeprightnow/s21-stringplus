#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = S21_NULL;
  const unsigned char *ptr = (const unsigned char *)str;
  unsigned char uc = (unsigned char)c;

  int found = 0;
  for (s21_size_t i = 0; i < n && !found; i++) {
    if (ptr[i] == uc) {
      res = (void *)(ptr + i);
      found = 1;
    }
  }
  return res;
}