#include "main.h"

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

int append_hexa_code(char code, char buff[], int i)
{
	char ma[] = "0123456789ABCDEF";

	if (code < 0)
		code *= -1;
	buff[i++] = '\\';
	buff[i++] = 'x';
	buff[i++] = ma[code / 16];
	buff[i] = ma[code % 16];
	return (3);
}

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long int num_conv(long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((short)num);
	return ((int)num);
}

long int unsigned_conv(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
