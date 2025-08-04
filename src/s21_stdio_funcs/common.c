#include <math.h>

#include "../s21_string.h"

int long_double_to_str(char *buf, long double val, int precision) {
  int len = 0;
  int res = 0;

  buf[0] = '\0';

  if (isnan(val)) {
    buf[0] = 'n';
    buf[1] = 'a';
    buf[2] = 'n';
    buf[3] = '\0';
    res = 3;
  }
  if (isinf(val)) {
    buf[0] = 'i';
    buf[1] = 'n';
    buf[2] = 'f';
    buf[3] = '\0';
    res = 3;
  }

  if (!res) {
    if (signbit(val)) {
      buf[len++] = '-';
      val = -val;
    }

    long double rounding = 0.5;
    for (int i = 0; i < precision; i++) rounding /= 10.0;
    val += rounding;

    int exp = 0;
    long double tmp = val;
    while (tmp >= 10.0) {
      tmp /= 10.0;
      exp++;
    }

    for (int i = exp; i >= 0; i--) {
      long double pow10 = 1.0;
      for (int j = 0; j < i; j++) pow10 *= 10.0;
      int digit = (int)(val / pow10);
      buf[len++] = '0' + digit;
      val -= digit * pow10;
    }

    if (precision > 0) {
      buf[len++] = '.';
      for (int i = 0; i < precision; i++) {
        val *= 10.0;
        int digit = (int)val;
        buf[len++] = '0' + digit;
        val -= digit;
      }
    }

    buf[len] = '\0';
    res = len;
  }
  return res;
}

void apply_padding(char *str, int *j, const char *buf, int left_align, char pad,
                   int pad_len) {
  if (!left_align)
    for (int p = 0; p < pad_len; p++) str[(*j)++] = pad;
  for (int k = 0; buf[k] != '\0'; ++k) str[(*j)++] = buf[k];
  if (left_align)
    for (int p = 0; p < pad_len; p++) str[(*j)++] = pad;
}