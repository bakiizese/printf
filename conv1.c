#include "main.h"
/**
 * p_char - entyr
 * @typ: var
 * @buff: array
 * @flags: var
 * @wid: var
 * @pre: var
 * @size: var
 * Return: write
 */
int p_char(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	char c = va_arg(typ, int);

	return (writing_char(c, buff, flags, wid, pre, size));
}
/**
 * p_string - entyr
 * @typ: var
 * @buff: array
 * @flags: var
 * @wid: var
 * @pre: var
 * @size: var
 * Return: write
 */
int p_string(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	int len = 0, i;
	char *str = va_arg(typ, char *);

	UNUSE(buff);
	UNUSE(pre);
	UNUSE(size);
	UNUSE(flags);
	UNUSE(wid);
	if (str == NULL)
	{
		str = "(null)";
		if (pre >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;

	if (pre >= 0 && pre < len)
		len = pre;
	if (wid > len)
	{
		if (flags & MINUS)
		{
			write(1, &str[0], len);
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (wid);
		}
	}
	return (write(1, str, len));
}
/**
 * p_percent - entyr
 * @typ: var
 * @buff: array
 * @flags: var
 * @wid: var
 * @pre: var
 * @size: var
 * Return: write
 */
int p_percent(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
    UNUSE(wid);
	UNUSE(pre);
	UNUSE(size);
	UNUSE(typ);
	UNUSE(buff);
	UNUSE(flags);
	return (write(1, "%%", 1));
}
/**
 * p_int - entyr
 * @typ: var
 * @buff: array
 * @flags: var
 * @wid: var
 * @pre: var
 * @size: var
 * Return: write
 */
int p_int(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	int i = SIZE_B - 2;
	int is_neg = 0;
	long int n = va_arg(typ, long int);
	unsigned long int m;

	n = num_conv(n, size);
	if (n == 0)
		buff[i--] = '0';
	buff[SIZE_B - 1] = '\0';
	m = (unsigned long int)n;
	if (n < 0)
	{
		m = (unsigned long int)((-1) * n);
		is_neg = 1;
	}
	while (m > 0)
	{
		buff[i--] = (m % 10) + '0';
        m /= 10;
	} i++;
	return (writing_number(is_neg, i, buff, flags, wid, pre, size));
}
/**
 * p_bunary - entyr
 * @typ: var
 * @buff: array
 * @flags: var
 * @wid: var
 * @pre: var
 * @size: var
 * Return: write
 */
int p_binary(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	unsigned int j, k, i, sum;
	unsigned int s[32];
	int c;

	UNUSE(buff);
	UNUSE(flags);
	UNUSE(wid);
	UNUSE(pre);
	UNUSE(size);
	j = va_arg(typ, unsigned int);
	k = 2147483648;
	s[0] = j / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		s[i] = (j / k) % 2;
	}
	for (i = 0, sum = 0, c = 0; i < 32; i++)
	{
		sum += s[i];
		if (sum || i == 31)
		{
			char x = '0' + s[i];

			write(1, &x, 1);
			c++;
		}
	}
	return (c);
}
