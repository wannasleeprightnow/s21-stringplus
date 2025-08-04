#include <math.h>
#include <stdarg.h>

#include "../s21_string.h"

void handle_gG(char *str, int *j, const char *format, int *i, va_list *args,
               Flags *flags) {
  int precision = (flags->accuracy == -1) ? 6 : flags->accuracy;
  if (precision == 0) precision = 1;

  long double val = flags->is_long == 'L' ? va_arg(*args, long double)
                                          : va_arg(*args, double);

  if (isnan(val)) {
    const char *nan_str = (format[*i] == 'G') ? "NAN" : "nan";
    s21_strncpy(str + *j, nan_str, 3);
    *j += 3;
    (*i)++;
    return;
  }
  if (isinf(val)) {
    if (signbit(val)) {
      str[(*j)++] = '-';
    } else if (flags->sign == '+') {
      str[(*j)++] = '+';
    } else if (flags->with_space) {
      str[(*j)++] = ' ';
    }
    const char *inf_str = (format[*i] == 'G') ? "INF" : "inf";
    s21_strncpy(str + *j, inf_str, 3);
    *j += 3;
    (*i)++;
    return;
  }

  int exp = 0;
  long double abs_val = fabsl(val);
  long double tmp = abs_val;

  if (tmp != 0.0) {
    while (tmp >= 10.0) {
      tmp /= 10.0;
      exp++;
    }
    while (tmp < 1.0) {
      tmp *= 10.0;
      exp--;
    }
  }

  char tmpbuf[128];
  int len = 0;

  if (exp < -4 || exp >= precision) {
    if (val < 0) {
      tmpbuf[len++] = '-';
      val = -val;
    } else if (flags->sign == '+') {
      tmpbuf[len++] = '+';
    } else if (flags->with_space) {
      tmpbuf[len++] = ' ';
    }
    int exp2 = 0;
    long double v = val;

    if (v != 0.0) {
      while (v >= 10.0) {
        v /= 10.0;
        exp2++;
      }
      while (v < 1.0) {
        v *= 10.0;
        exp2--;
      }
    }

    int mantissa_start = len;
    len += long_double_to_str(tmpbuf + len, v, precision - 1);

    if (!flags->with_lattice) {
      int end = len - 1;
      while (end > mantissa_start && tmpbuf[end] == '0') end--;
      if (tmpbuf[end] == '.' && !flags->with_lattice) end--;
      len = end + 1;
      tmpbuf[len] = '\0';
    }

    tmpbuf[len++] = (format[*i] == 'G') ? 'E' : 'e';
    tmpbuf[len++] = (exp2 >= 0) ? '+' : '-';
    int abs_exp = (exp2 >= 0) ? exp2 : -exp2;

    if (abs_exp < 10) {
      tmpbuf[len++] = '0';
      tmpbuf[len++] = '0' + abs_exp;
    } else {
      tmpbuf[len++] = '0' + (abs_exp / 10);
      tmpbuf[len++] = '0' + (abs_exp % 10);
    }

    tmpbuf[len] = '\0';
  } else {
    if (val < 0) {
      tmpbuf[len++] = '-';
      val = -val;
    } else if (flags->sign == '+') {
      tmpbuf[len++] = '+';
    } else if (flags->with_space) {
      tmpbuf[len++] = ' ';
    }

    int number_start = len;
    int decimal_precision = precision - (exp + 1);
    if (decimal_precision < 0) decimal_precision = 0;

    len += long_double_to_str(tmpbuf + len, val, decimal_precision);

    if (!flags->with_lattice) {
      int end = len - 1;
      while (end > number_start && tmpbuf[end] == '0') end--;
      if (tmpbuf[end] == '.' && !flags->with_lattice) end--;
      len = end + 1;
      tmpbuf[len] = '\0';
    }
  }

  int left_align = (flags->sign == '-');
  char pad = ' ';
  if (flags->with_zeros && !left_align) pad = '0';
  int width = (flags->width > 0) ? flags->width : 0;
  int reslen = s21_strlen(tmpbuf);
  int pad_len = (width > reslen) ? (width - reslen) : 0;

  if (!left_align && pad == '0' &&
      (tmpbuf[0] == '-' || tmpbuf[0] == '+' || tmpbuf[0] == ' ')) {
    str[(*j)++] = tmpbuf[0];
    for (int p = 0; p < pad_len; p++) str[(*j)++] = '0';
    for (int k = 1; tmpbuf[k] != '\0'; ++k) str[(*j)++] = tmpbuf[k];
  } else {
    apply_padding(str, j, tmpbuf, left_align, pad, pad_len);
  }

  (*i)++;
}