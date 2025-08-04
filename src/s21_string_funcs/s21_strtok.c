#include "../s21_string.h"

static char *last_token = S21_NULL;

static char *skip_delim(char *str, const char *delim) {
  while (*str != '\0') {
    const char *d = delim;
    int is_delim = 0;
    while (*d != '\0') {
      if (*str == *d) {
        is_delim = 1;
        break;
      }
      d++;
    }
    if (!is_delim) {
      break;
    }
    str++;
  }
  return str;
}

char *s21_strtok(char *str, const char *delim) {
  char *token_start;

  if (str == S21_NULL) {
    if (last_token == S21_NULL) {
      return S21_NULL;
    }
    str = last_token;
  }

  str = skip_delim(str, delim);
  if (*str == '\0') {
    last_token = S21_NULL;
    return S21_NULL;
  }

  token_start = str;
  str += s21_strcspn(str, delim);

  if (*str != '\0') {
    *str = '\0';
    last_token = str + 1;
  } else {
    last_token = S21_NULL;
  }

  return token_start;
}