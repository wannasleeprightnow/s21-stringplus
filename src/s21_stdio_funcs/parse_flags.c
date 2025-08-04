#include <stdlib.h>

#include "../s21_string.h"

int parse_number(const char *format, int *s) {
  int start = *s, val = 0;
  while (format[*s] >= '0' && format[*s] <= '9') (*s)++;
  if (*s > start) {
    char buf[32];
    int len = *s - start;
    if (len > 31) len = 31;
    for (int i = 0; i < len; i++) buf[i] = format[start + i];
    buf[len] = '\0';
    val = atoi(buf);
    (*s)--;
  }
  return val;
}

int parse_flags(const char *format, int i, va_list *args, Flags *flags) {
  int s = i + 1, stop = 0, point_setted = 0;
  while (format[s] && !stop) {
    char c = format[s];
    if (c == '-' || c == '+')
      flags->sign = c;
    else if (c == ' ')
      flags->with_space = 1;
    else if (c == '#')
      flags->with_lattice = 1;
    else if (c == '*') {
      int val = va_arg(*args, int);
      if (!point_setted)
        flags->width = val;
      else
        flags->accuracy = val;
    } else if (c == 'l' || c == 'h' || c == 'L')
      flags->is_long = c;
    else if (c == '.') {
      point_setted = 1;
      flags->accuracy = 0;
    } else if (c == '0' && !point_setted &&
               (s == i + 1 || !s21_strchr("0123456789", format[s - 1]))) {
      flags->with_zeros = 1;
    } else if (c >= '0' && c <= '9') {
      int val = parse_number(format, &s);
      if (!point_setted)
        flags->width = val;
      else
        flags->accuracy = val;
    } else {
      if (s21_strchr("diuoxXfFeEgGaAcspn%", c)) {
        stop = 1;
        s--;
      }
    }
    s++;
  }
  return s;
}