#include <stdarg.h>

#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)

typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
const char *s21_strerror(int errnum);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

typedef struct Flags {
  char is_long;
  char sign;
  int with_space;
  int with_lattice;
  int with_zeros;
  int width;
  int accuracy;
} Flags;

int s21_sprintf(char *str, const char *format, ...);
int parse_flags(const char *format, int i, va_list *args, Flags *flags);
int parse_number(const char *format, int *s);
int long_double_to_str(char *buf, long double val, int precision);
void apply_padding(char *str, int *j, const char *buf, int left_align, char pad,
                   int pad_len);
void handle_percent(char *str, int *j);
void handle_eE(char *str, int *j, const char *format, int *i, va_list *args,
               Flags *flags);
void handle_gG(char *str, int *j, const char *format, int *i, va_list *args,
               Flags *flags);
void handle_xX(char *str, int *j, const char *format, int *i, va_list *args,
               Flags *flags);
void handle_di(char *str, int *j, int *i, va_list *args, Flags *flags);
void handle_u(char *str, int *j, int *i, va_list *args, Flags *flags);
void handle_o(char *str, int *j, int *i, va_list *args, Flags *flags);
void handle_c(char *str, int *j, int *i, va_list *args, Flags *flags);
void handle_s(char *str, int *j, int *i, va_list *args, Flags *flags);
void handle_p(char *str, int *j, int *i, va_list *args, Flags *flags);
void handle_fF(char *str, int *j, int *i, va_list *args, Flags *flags);
void handle_n(int *j, int *i, va_list *args);

#endif