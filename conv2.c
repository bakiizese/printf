#include "main.h"

int p_unsigned(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	int i = SIZE_B - 2;
	unsigned long int m = va_arg(typ, unsigned long int);
	m = unsigned_conv(m, size);
	if (m == 0)
		buff[i--] = '0';
	buff[SIZE_B - 1] = '\0';
	while (m > 0)
	{
		buff[i--] = (m % 10) + '0';
		m /= 10;
	} i++;
	return (writing_unsigned(0, i, buff, flags, wid, pre, size));
}

int p_octal(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;
	int i = SIZE_B - 2;

	UNUSE(wid);
	num = unsigned_conv(num, size);
	if (num == 0)
		buff[i--] = '0';
	buff[SIZE_B - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & HASH && init_num != 0)
		buff[i--] = '0';
	i++;
	return (writing_unsigned(0, i, buff, flags, wid, pre, size));
}

int p_hexadecimal(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	return (p_hexa(typ, "0123456789abcdef", buff,
		flags, 'x', wid, pre, size));
}

int p_hexa_upper(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	return (p_hexa(typ, "0123456789ABCDEF", buff,
		flags, 'X', wid, pre, size));
}

int p_hexa(va_list typ, char ma[], char buff[], int flags, char f_ch, int wid, int pre, int size)
{
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;
	int i = SIZE_B - 2;

	UNUSE(wid);
	num = unsigned_conv(num, size);
	if (num == 0)
		buff[i--] = '0';
	buff[SIZE_B - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = ma[num % 16];
		num /= 16;
	}
	if (flags & HASH && init_num != 0)
	{
		buff[i--] = f_ch;
		buff[i--] = '0';
	} i++;
	return (writing_unsigned(0, i, buff, flags, wid, pre, size));
}
