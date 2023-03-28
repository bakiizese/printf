#include "main.h"

int size_g(const char *format, int *i)
{
	int id = *i + 1;
	int size = 0;

	if (format[id] == 'l')
		size = LONG;
	else if (format[id] == 'h')
		size = SHORT;
	if (size == 0)
		*i = id - 1;
	else
		*i = id;
	return (size);
}
