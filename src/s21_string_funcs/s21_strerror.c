#include "s21_strerror.h"

#include <stdio.h>

#include "../s21_string.h"

const char *s21_strerror(int errnum) {
  static char unk_err_buf[64];
  if (errnum < 0 ||
      errnum > (int)(sizeof(error_messages) / sizeof(error_messages[0]) - 1)) {
    snprintf(unk_err_buf, sizeof(unk_err_buf), "Unknown error %d", errnum);
    return unk_err_buf;
  }
  return error_messages[errnum];
}