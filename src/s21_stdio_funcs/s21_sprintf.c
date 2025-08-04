#include <stdarg.h>

#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int i = 0;
  int j = 0;

  while (format[i] != '\0') {
    if (format[i] == '%') {
      if (format[i + 1] == '%') {
        handle_percent(str, &j);
        i += 2;
        continue;
      }
      Flags flags = {0, 0, 0, 0, 0, 0, -1};
      i = parse_flags(format, i, &args, &flags);

      switch (format[i]) {
        case 'e':
        case 'E':
          handle_eE(str, &j, format, &i, &args, &flags);
          break;
        case 'g':
        case 'G':
          handle_gG(str, &j, format, &i, &args, &flags);
          break;
        case 'x':
        case 'X':
          handle_xX(str, &j, format, &i, &args, &flags);
          break;
        case 'd':
        case 'i':
          handle_di(str, &j, &i, &args, &flags);
          break;
        case 'u':
          handle_u(str, &j, &i, &args, &flags);
          break;
        case 'o':
          handle_o(str, &j, &i, &args, &flags);
          break;
        case 'c':
          handle_c(str, &j, &i, &args, &flags);
          break;
        case 's':
          handle_s(str, &j, &i, &args, &flags);
          break;
        case 'p':
          handle_p(str, &j, &i, &args, &flags);
          break;
        case 'f':
        case 'F':
          handle_fF(str, &j, &i, &args, &flags);
          break;
        case 'n':
          handle_n(&j, &i, &args);
          break;
        default:
          str[j++] = format[i++];
          break;
      }
    } else {
      str[j++] = format[i++];
    }
  }
  str[j] = '\0';
  va_end(args);
  return j;
}
