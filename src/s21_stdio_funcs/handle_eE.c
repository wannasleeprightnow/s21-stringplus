#include <math.h>
#include <stdarg.h>

#include "../s21_string.h"

void handle_eE(char *str, int *j, const char *format, int *i, va_list *args,
               Flags *flags) {
  int precision = (flags->accuracy == -1) ? 6 : flags->accuracy;
  int width = (flags->width > 0) ? flags->width : 0;
  int left_align = (flags->sign == '-');
  char pad = ' ';
  if (flags->with_zeros && !left_align) pad = '0';
  long double val = flags->is_long == 'L' ? va_arg(*args, long double)
                                          : va_arg(*args, double);

  if (isnan(val)) {
    const char *nan_str = (format[*i] == 'E') ? "NAN" : "nan";
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
    const char *inf_str = (format[*i] == 'E') ? "INF" : "inf";
    s21_strncpy(str + *j, inf_str, 3);
    *j += 3;
    (*i)++;
    return;
  }

  char tmpbuf[128];
  int pos = 0;

  int is_negative = (val < 0);
  if (is_negative) {
    tmpbuf[pos++] = '-';
    val = -val;
  } else if (flags->sign == '+') {
    tmpbuf[pos++] = '+';
  } else if (flags->with_space) {
    tmpbuf[pos++] = ' ';
  }

  int exp = 0;
  long double v = val;
  if (v != 0.0) {
    while (v >= 10.0) {
      v /= 10.0;
      exp++;
    }
    while (v < 1.0) {
      v *= 10.0;
      exp--;
    }
  }

  char mantissa[64];
  if (precision == 0) {
    long double integral_part;
    long double fractional_part = modfl(v, &integral_part);
    if (fractional_part >= 0.5) integral_part += 1.0;

    int int_part = (int)integral_part;
    int mantissa_pos = 0;

    if (int_part == 0) {
      mantissa[mantissa_pos++] = '0';
    } else {
      char digits[20];
      int digits_count = 0;

      while (int_part > 0) {
        digits[digits_count++] = '0' + (int_part % 10);
        int_part /= 10;
      }

      for (int d = digits_count - 1; d >= 0; d--) {
        mantissa[mantissa_pos++] = digits[d];
      }
    }

    if (flags->with_lattice) {
      mantissa[mantissa_pos++] = '.';
    }

    mantissa[mantissa_pos] = '\0';
  } else {
    long_double_to_str(mantissa, v, precision);
  }

  for (int k = 0; mantissa[k] != '\0'; k++) {
    tmpbuf[pos++] = mantissa[k];
  }

  tmpbuf[pos++] = (format[*i] == 'E') ? 'E' : 'e';
  tmpbuf[pos++] = (exp >= 0) ? '+' : '-';
  int abs_exp = (exp >= 0) ? exp : -exp;

  if (abs_exp >= 100) {
    tmpbuf[pos++] = '0' + (abs_exp / 100);
    tmpbuf[pos++] = '0' + ((abs_exp / 10) % 10);
    tmpbuf[pos++] = '0' + (abs_exp % 10);
  } else {
    tmpbuf[pos++] = '0' + (abs_exp / 10);
    tmpbuf[pos++] = '0' + (abs_exp % 10);
  }

  tmpbuf[pos] = '\0';

  int total_len = pos;
  int pad_len = (width > total_len) ? (width - total_len) : 0;

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
