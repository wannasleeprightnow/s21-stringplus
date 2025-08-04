#include <stdarg.h>
#include <stdint.h>

#include "../s21_string.h"

void handle_fF(char *str, int *j, int *i, va_list *args, Flags *flags) {
  int precision = (flags->accuracy == -1) ? 6 : flags->accuracy;
  int left_align = (flags->sign == '-');
  char pad = (flags->with_zeros && !left_align) ? '0' : ' ';

  char float_str[4096];
  long double arg;

  if (flags->is_long == 'L') {
    arg = va_arg(*args, long double);
  } else {
    arg = va_arg(*args, double);
  }
  long_double_to_str(float_str, arg, precision);

  if (precision == 0 && flags->with_lattice) {
    if (s21_strchr(float_str, '.') == S21_NULL) {
      s21_strncat(float_str, ".", 1);
    }
  }

  char final_str_to_pad[4100];
  char *p = final_str_to_pad;
  s21_size_t remaining_space = sizeof(final_str_to_pad);

  if (float_str[0] != '-') {
    if (flags->sign == '+') {
      *p++ = '+';
      remaining_space--;
    } else if (flags->with_space) {
      *p++ = ' ';
      remaining_space--;
    }
  }

  s21_strncpy(p, float_str, remaining_space - 1);
  final_str_to_pad[sizeof(final_str_to_pad) - 1] = '\0';

  int final_len = s21_strlen(final_str_to_pad);
  int pad_len = (flags->width > final_len) ? (flags->width - final_len) : 0;

  if (pad == '0') {
    char sign_char = 0;
    char *number_part = final_str_to_pad;

    if (final_str_to_pad[0] == '+' || final_str_to_pad[0] == '-' ||
        final_str_to_pad[0] == ' ') {
      sign_char = final_str_to_pad[0];
      number_part++;
    }

    if (sign_char) str[(*j)++] = sign_char;
    for (int p = 0; p < pad_len; p++) str[(*j)++] = '0';
    for (int k = 0; number_part[k] != '\0'; k++) str[(*j)++] = number_part[k];

  } else {
    apply_padding(str, j, final_str_to_pad, left_align, ' ', pad_len);
  }

  (*i)++;
}