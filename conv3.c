#include "main.h"

int p_pointer(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	char exe = 0, dep = ' ';
	int id = SIZE_B - 2, len = 2, dep_srt = 1;
	unsigned long adres;
	char ma[] = "0123456789abcdef";
	void *adds = va_arg(typ, void *);

	UNUSE(wid);
	UNUSE(size);
	if (adds == NULL)
		return (write(1, "(nil)", 5));
	buff[SIZE_B - 1] = '\0';
	UNUSE(pre);
	adres = (unsigned long)adds;
	while (adres > 0)
	{
		buff[id--] = ma[adres % 16];
		adres /= 16;
		len++;
	}
	if ((flags & ZERO) && !(flags & MINUS))
		dep = '0';
	if (flags & PLUS)
		exe = '+', len++;
	else if (flags & SPACE)
		exe = ' ', len++;
	id++;
	return (writing_pointer(buff, id, len, wid, flags, dep, exe, dep_srt));
}

int p_non_printable(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	int i = 0, sd = 0;
	char *str = va_arg(typ, char *);

	UNUSE(flags);
	UNUSE(wid);
	UNUSE(pre);
	UNUSE(size);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + sd] = str[i];
		else
			sd += append_hexa_code(str[i], buff, i + sd);
		i++;
	}
	buff[i + sd] = '\0';
	return (write(1, buff, i + sd));
}

int p_reverse(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
	char *str;
	int i, c = 0;

	UNUSE(buff);
	UNUSE(flags);
	UNUSE(wid);
	UNUSE(size);
	str = va_arg(typ, char *);
	if (str == NULL)
	{
		UNUSE(pre);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++);

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		c++;
	}
	return (c);
}

int p_rot13string(va_list typ, char buff[], int flags, int wid, int pre, int size)
{
    char inside[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outside[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char z;
	char *str;
	unsigned int i, j;
	int c = 0;

	str = va_arg(typ, char *);
	UNUSE(buff);
	UNUSE(flags);
	UNUSE(wid);
	UNUSE(pre);
	UNUSE(size);
	if (str == NULL)
		str = "(nil)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; inside[j]; j++)
		{
			if (inside[j] == str[i])
			{
				z = outside[j];
				write(1, &z, 1);
				c++;
				break;
			}
		}
		if (!inside[j])
		{
			z = str[i];
			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}
