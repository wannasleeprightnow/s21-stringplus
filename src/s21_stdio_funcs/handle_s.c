#include <stdarg.h>
#include <stdlib.h>

#include "../s21_string.h"

void handle_s(char *str, int *j, int *i, va_list *args, Flags *flags) {
  char *arg = va_arg(*args, char *);
  if (arg == NULL) arg = "(null)";

  int arg_len = 0;
  while (arg[arg_len] != '\0') arg_len++;

  if (flags->accuracy >= 0 && flags->accuracy < arg_len) {
    arg_len = flags->accuracy;
  }
  if (flags->accuracy == 0) {
    arg_len = 0;
  }

  int left_align = (flags->sign == '-');
  int width = (flags->width > 0) ? flags->width : 0;
  int pad_len = (width > arg_len) ? (width - arg_len) : 0;

  if (!left_align)
    for (int p = 0; p < pad_len; p++) str[(*j)++] = ' ';
  for (int x = 0; x < arg_len; x++) str[(*j)++] = arg[x];
  if (left_align)
    for (int p = 0; p < pad_len; p++) str[(*j)++] = ' ';

  (*i)++;
}