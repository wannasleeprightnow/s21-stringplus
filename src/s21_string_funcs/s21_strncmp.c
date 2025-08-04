#include "../s21_string.h"

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  int res = 0;
  const unsigned char* string1 = (const unsigned char*)str1;
  const unsigned char* string2 = (const unsigned char*)str2;

  s21_size_t i = 0;

  while (res == 0 && i < n) {
    if (string1[i] != string2[i]) {
      res = string1[i] - string2[i];
    } else if (string1[i] == '\0') {
      break;
    }
    i++;
  }
  return res;
}