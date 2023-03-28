#include "main.h"

int precision_g(const char *format, int *i, va_list list)
{
	int id = *i + 1;
	int pre = -1;

	if (format[id] != '.')
		return (pre);
	pre = 0;
	for (id += 1; format[id] != '\0'; id++)
	{
		if (is_digit(format[id]))
		{
			pre *= 10;
			pre += format[id] - '0';
		}
		else if (format[id] == '*')
		{
			id++;
			pre = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = id - 1;
	return (pre);
}
