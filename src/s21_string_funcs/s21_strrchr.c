#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last_pos = S21_NULL;

  for (; *str != '\0'; str++) {
    if (*str == (char)c) {
      last_pos = str;
    }
  }

  if ((char)c == '\0') return (char *)str;
  return (char *)last_pos;
}