#include <stdlib.h>

#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  int str_len = 0;
  while (str[str_len] != '\0') {
    str_len++;
  }
  char *strcopy = (char *)malloc((str_len + 1) * sizeof(char));
  if (strcopy != NULL) {
    for (int i = 0; i < str_len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        strcopy[i] = str[i] - 32;
      } else {
        strcopy[i] = str[i];
      }
    }

    strcopy[str_len] = '\0';
  }
  return (void *)strcopy;
}