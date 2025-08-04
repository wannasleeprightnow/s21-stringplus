#include "../s21_string.h"

void handle_percent(char *str, int *j) {
  if (str && j && *j >= 0) {
    str[(*j)++] = '%';
  }
}