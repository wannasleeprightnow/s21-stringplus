#include <stdarg.h>

#include "../s21_string.h"

void handle_xX(char *str, int *j, const char *format, int *i, va_list *args,
               Flags *flags) {
  int uppercase = (format[*i] == 'X');
  unsigned long long val = 0;

  switch (flags->is_long) {
    case 'l':
      val = va_arg(*args, unsigned long int);
      break;
    case 'h':
      val = (unsigned short int)va_arg(*args, unsigned int);
      break;
    default:
      val = va_arg(*args, unsigned int);
      break;
  }

  unsigned long long original_val = val;

  if (val == 0 && flags->accuracy == 0) {
    (*i)++;
    return;
  }

  char hexbuf[32];
  int hexlen = 0;

  if (val == 0) {
    hexbuf[hexlen++] = '0';
  } else {
    while (val > 0) {
      int digit = val % 16;
      if (digit < 10) {
        hexbuf[hexlen++] = '0' + digit;
      } else {
        hexbuf[hexlen++] = (uppercase ? 'A' : 'a') + (digit - 10);
      }
      val /= 16;
    }
  }

  int precision = (flags->accuracy >= 0) ? flags->accuracy : 1;
  int zeros_to_pad = (precision > hexlen) ? (precision - hexlen) : 0;

  char tmpbuf[64];
  int pos = 0;

  if (flags->with_lattice && (original_val != 0)) {
    tmpbuf[pos++] = '0';
    tmpbuf[pos++] = uppercase ? 'X' : 'x';
  }

  for (int z = 0; z < zeros_to_pad; z++) tmpbuf[pos++] = '0';
  for (int k = hexlen - 1; k >= 0; k--) tmpbuf[pos++] = hexbuf[k];
  tmpbuf[pos] = '\0';

  int left_align = (flags->sign == '-');
  char pad = ' ';
  if (flags->with_zeros && !left_align && flags->accuracy < 0) pad = '0';
  int width = (flags->width > 0) ? flags->width : 0;
  int total_len = s21_strlen(tmpbuf);
  int pad_len = (width > total_len) ? (width - total_len) : 0;

  if (!left_align && pad == '0' && flags->with_lattice && pos >= 2 &&
      original_val != 0) {
    str[(*j)++] = tmpbuf[0];
    str[(*j)++] = tmpbuf[1];
    for (int p = 0; p < pad_len; p++) str[(*j)++] = '0';
    for (int k = 2; tmpbuf[k] != '\0'; k++) str[(*j)++] = tmpbuf[k];
  } else {
    apply_padding(str, j, tmpbuf, left_align, pad, pad_len);
  }

  (*i)++;
}