#include "main.h"

int width_g(const char *format, int *i, va_list list)
{
	int id;
	int wid = 0;

	for (id = *i + 1; format[id] != '\0'; id++)
	{
		if (is_digit(format[id]))
		{
			wid *= 10;
			wid += format[id] - '0';
		}
		else if (format[id] == '*')
		{
			id++;
			wid = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = id - 1;
	return (wid);
}
