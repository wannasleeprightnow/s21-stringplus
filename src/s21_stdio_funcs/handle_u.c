#include <stdarg.h>

#include "../s21_string.h"

void handle_u(char *str, int *j, int *i, va_list *args, Flags *flags) {
  unsigned long arg = 0;

  if (flags->is_long == 'l') {
    arg = va_arg(*args, unsigned long);
  } else if (flags->is_long == 'h') {
    arg = (unsigned short)va_arg(*args, unsigned int);
  } else {
    arg = va_arg(*args, unsigned int);
  }

  int arg_len = 0;
  unsigned long tmp = arg;
  if (tmp == 0)
    arg_len = 1;
  else
    while (tmp > 0) {
      arg_len++;
      tmp /= 10;
    }

  int precision = (flags->accuracy >= 0) ? flags->accuracy : 1;
  int zeros_to_pad = (precision > arg_len) ? (precision - arg_len) : 0;

  char strarg[128] = {0};
  int pos = 0;

  for (int z = 0; z < zeros_to_pad; z++) strarg[pos++] = '0';

  if (arg == 0 && precision == 0) {
  } else if (arg == 0) {
    strarg[pos++] = '0';
  } else {
    int start = pos;
    unsigned long t = arg;
    for (int k = arg_len - 1; k >= 0; k--) {
      strarg[start + k] = '0' + (t % 10);
      t /= 10;
    }
    pos += arg_len;
  }
  strarg[pos] = '\0';

  int left_align = (flags->sign == '-');
  char pad = ' ';
  if (flags->with_zeros && flags->accuracy < 0 && !left_align) pad = '0';
  int width = (flags->width > 0) ? flags->width : 0;
  int total_len = s21_strlen(strarg);
  int pad_len = (width > total_len) ? (width - total_len) : 0;

  apply_padding(str, j, strarg, left_align, pad, pad_len);
  (*i)++;
}
