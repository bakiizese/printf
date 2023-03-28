#include "main.h"

void print_buffer(char buff[], int *id)
{
	if (*id > 0)
		write(1, &buff[0], *id);

	*id = 0;
}
int _printf(const char *format, ...)
{
	int i, ted = 0, ted_c = 0;
	int flags, wid, pre, size, id = 0;
	va_list ap;
	char buff[SIZE_B];

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[id++] = format[i];
			if (id == SIZE_B)
				print_buffer(buff, &id);
			ted_c++;
		}
		else
		{
			print_buffer(buff, &id);
			flags = flags_g(format, &i);
			wid = width_g(format, &i, ap);
			pre = precision_g(format, &i, ap);
			size = size_g(format, &i);
			++i;
			ted = printing_handler(format, &i, ap, buff,
				flags, wid, pre, size);
			if (ted == -1)
				return (-1);
			ted_c += ted;
		}
	}
	print_buffer(buff, &id);
	va_end(ap);
	return (ted_c);
}
