#include <stdarg.h>

#include "../s21_string.h"

void handle_o(char *str, int *j, int *i, va_list *args, Flags *flags) {
  unsigned long long arg = 0;
  if (flags->is_long == 'l')
    arg = va_arg(*args, unsigned long int);
  else if (flags->is_long == 'h')
    arg = (unsigned short int)va_arg(*args, unsigned int);
  else
    arg = va_arg(*args, unsigned int);

  if (arg == 0 && flags->accuracy == 0) {
    if (flags->with_lattice) {
      str[(*j)++] = '0';
    }
    (*i)++;
    return;
  }

  char octbuf[128] = {0};
  int octlen = 0;

  if (arg == 0) {
    octbuf[octlen++] = '0';
  } else {
    unsigned long long tmp = arg;
    while (tmp > 0) {
      octbuf[octlen++] = '0' + (tmp % 8);
      tmp /= 8;
    }
  }

  int precision = (flags->accuracy >= 0) ? flags->accuracy : 1;
  int zeros_to_pad = (precision > octlen) ? (precision - octlen) : 0;

  char tmpbuf[64] = {0};
  int pos = 0;

  if (flags->with_lattice && zeros_to_pad == 0) {
    if (octlen == 0 || octbuf[octlen - 1] != '0') {
      tmpbuf[pos++] = '0';
    }
  }

  for (int z = 0; z < zeros_to_pad; z++) tmpbuf[pos++] = '0';
  for (int k = octlen - 1; k >= 0; k--) tmpbuf[pos++] = octbuf[k];
  tmpbuf[pos] = '\0';

  int left_align = (flags->sign == '-');
  char pad = ' ';
  if (flags->with_zeros && !left_align && flags->accuracy < 0) pad = '0';
  int width = (flags->width > 0) ? flags->width : 0;
  int total_len = s21_strlen(tmpbuf);
  int pad_len = (width > total_len) ? (width - total_len) : 0;

  apply_padding(str, j, tmpbuf, left_align, pad, pad_len);
  (*i)++;
}