#include <stdarg.h>

#include "../s21_string.h"

void handle_c(char *str, int *j, int *i, va_list *args, Flags *flags) {
  unsigned char arg = va_arg(*args, int);

  int left_align = (flags->sign == '-');
  int width = (flags->width > 0) ? flags->width : 0;
  int pad_len = (width > 1) ? (width - 1) : 0;

  if (!left_align)
    for (int p = 0; p < pad_len; p++) str[(*j)++] = ' ';
  str[(*j)++] = arg;
  if (left_align)
    for (int p = 0; p < pad_len; p++) str[(*j)++] = ' ';

  (*i)++;
}