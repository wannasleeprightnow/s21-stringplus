#include <stdarg.h>

#include "../s21_string.h"

void handle_di(char *str, int *j, int *i, va_list *args, Flags *flags) {
  long long arg = 0;

  if (flags->is_long == 'l')
    arg = va_arg(*args, long int);
  else if (flags->is_long == 'h')
    arg = (short int)va_arg(*args, int);
  else
    arg = va_arg(*args, int);

  int is_negative = arg < 0;
  long long abs_arg = is_negative ? -arg : arg;

  int arg_len = 0;
  long long tmp = abs_arg;
  if (tmp == 0)
    arg_len = 1;
  else
    while (tmp > 0) {
      arg_len++;
      tmp /= 10;
    }

  int precision = (flags->accuracy >= 0) ? flags->accuracy : 1;
  int zeros_to_pad = (precision > arg_len) ? (precision - arg_len) : 0;

  char strarg[128];
  int pos = 0;

  if (is_negative)
    strarg[pos++] = '-';
  else if (flags->sign == '+')
    strarg[pos++] = '+';
  else if (flags->with_space)
    strarg[pos++] = ' ';

  for (int z = 0; z < zeros_to_pad; z++) strarg[pos++] = '0';

  if (abs_arg == 0 && precision == 0) {
  } else if (abs_arg == 0) {
    strarg[pos++] = '0';
  } else {
    int start = pos;
    long long t = abs_arg;
    for (int k = arg_len - 1; k >= 0; k--) {
      strarg[start + k] = '0' + (t % 10);
      t /= 10;
    }
    pos += arg_len;
  }
  strarg[pos] = '\0';

  int left_align = (flags->sign == '-' || flags->width < 0);
  char pad = ' ';
  if (flags->with_zeros && flags->accuracy < 0 && !left_align) pad = '0';
  int width = flags->width > 0 ? flags->width : -flags->width;
  int total_len = s21_strlen(strarg);
  int pad_len = (width > total_len) ? (width - total_len) : 0;

  if (!left_align && pad == '0' &&
      (strarg[0] == '-' || strarg[0] == '+' || strarg[0] == ' ')) {
    str[(*j)++] = strarg[0];
    for (int p = 0; p < pad_len; p++) str[(*j)++] = '0';
    for (int k = 1; strarg[k] != '\0'; k++) str[(*j)++] = strarg[k];
  } else {
    apply_padding(str, j, strarg, left_align, pad, pad_len);
  }

  (*i)++;
}
