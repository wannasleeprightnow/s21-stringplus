#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  const unsigned char *ptr = (const unsigned char *)str;
  unsigned char uc = (unsigned char)c;
  s21_size_t i = 0;

  int found = 0;
  while (ptr[i] != '\0' && !found) {
    if (ptr[i] == uc) {
      res = (char *)(ptr + i);
      found = 1;
    }
    i++;
  }
  if (!found && ptr[i] == '\0' && uc == '\0') {
    res = (char *)(ptr + i);
  }

  return res;
}