#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

#include "../s21_string.h"

void handle_p(char *str, int *j, int *i, va_list *args, Flags *flags) {
  void *ptr = va_arg(*args, void *);
  if (ptr == NULL) {
    char nil_str[] = "(nil)";
    for (int k = 0; nil_str[k] != '\0'; k++) {
      str[(*j)++] = nil_str[k];
    }

    (*i)++;
    return;
  }
  uintptr_t uintptr = (uintptr_t)ptr;

  char hexbuf[32];
  int hexlen = 0;
  if (uintptr == 0) {
    hexbuf[hexlen++] = '0';
  } else {
    uintptr_t tmp = uintptr;
    while (tmp > 0) {
      int digit = tmp % 16;
      hexbuf[hexlen++] = "0123456789abcdef"[digit];
      tmp /= 16;
    }
  }
  int precision = (flags->accuracy >= 0) ? flags->accuracy : 1;
  int zeros_to_pad = (precision > hexlen) ? (precision - hexlen) : 0;

  char ptrbuf[64];
  int pos = 0;
  ptrbuf[pos++] = '0';
  ptrbuf[pos++] = 'x';
  for (int z = 0; z < zeros_to_pad; z++) ptrbuf[pos++] = '0';
  for (int k = hexlen - 1; k >= 0; k--) ptrbuf[pos++] = hexbuf[k];
  ptrbuf[pos] = '\0';

  int left_align = (flags->sign == '-');
  char pad = ' ';
  if (flags->with_zeros && !left_align && flags->accuracy < 0) pad = '0';
  int width = (flags->width > 0) ? flags->width : 0;
  int total_len = s21_strlen(ptrbuf);
  int pad_len = (width > total_len) ? (width - total_len) : 0;

  if (!left_align && pad == '0' && pos >= 2) {
    str[(*j)++] = ptrbuf[0];
    str[(*j)++] = ptrbuf[1];
    for (int p = 0; p < pad_len; p++) str[(*j)++] = '0';
    for (int k = 2; ptrbuf[k] != '\0'; k++) str[(*j)++] = ptrbuf[k];
  } else {
    apply_padding(str, j, ptrbuf, left_align, pad, pad_len);
  }

  (*i)++;
}