#include <stdarg.h>

#include "../s21_string.h"

void handle_n(int *j, int *i, va_list *args) {
  int *ptr = va_arg(*args, int *);
  *ptr = *j;
  (*i)++;
}