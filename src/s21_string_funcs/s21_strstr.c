#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') return (char *)haystack;

  for (; *haystack != '\0'; haystack++) {
    const char *h = haystack, *n = needle;
    while (*h == *n && *n != '\0') {
      h++;
      n++;
    }
    if (*n == '\0') return (char *)haystack;
  }
  return S21_NULL;
}