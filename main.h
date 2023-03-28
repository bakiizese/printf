#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSE(i) (void)(i)
#define LONG 2
#define SHORT 1
#define SIZE_B 1024
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16

struct con
{
	char con;
	int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct con conv;

int _printf(const char *format, ...);
int printing_handler(const char *con, int *i, va_list list, char buff[], int flags, int wid, int pre, int size);
int p_reverse(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_rot13string(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_char(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_string(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_percent(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_int(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_binary(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_unsigned(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_octal(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_hexadecimal(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_hexa_upper(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_hexa(va_list typ, char ma[], char buff[], int flags, char f_ch, int wid, int pre, int size);
int p_non_printable(va_list typ, char buff[], int flags, int wid, int pre, int size);
int p_pointer(va_list typ, char buff[], int flags, int wid, int pre, int size);
int writing_char(char c, char buff[], int flags, int wid, int pre, int size);
int writing_number(int is_pos, int id, char buff[], int flags, int wid, int pre, int size);
int writing_num(int id, char buff[], int flags, int wid, int pre, int len, char dep, char exe);
int writing_pointer(char buff[], int id, int len, int wid, int flags, char dep, char exe, int dep_str);
int writing_unsigned(int is_neg, int id, char buff[], int flags, int wid, int pre, int size);
int flags_g(const char *format, int *i);
int width_g(const char *format, int *i, va_list list);
int precision_g(const char *format, int *i, va_list list);
int size_g(const char *format, int *i);
int is_printable(char);
int is_digit(char);
int append_hexa_code(char, char[], int);
long int num_conv(long int num, int size);
long int unsigned_conv(unsigned long int num, int size);

#endif
