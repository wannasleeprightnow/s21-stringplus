#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  unsigned char *str_dest = (unsigned char *)dest;
  const unsigned char *str_src = (const unsigned char *)src;
  s21_size_t i = 0;
  for (i = 0; i < n && str_src[i] != '\0'; i++) {
    str_dest[i] = str_src[i];
  }
  if (i < n) {
    for (; i < n; i++) {
      str_dest[i] = '\0';
    }
  }

  return dest;
}