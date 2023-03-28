#include "main.h"

int printing_handler(const char *con, int *ind, va_list list, char buff[], int flags, int wid, int pre, int size)
{
	int i, len = 0, ted = -1;
	conv conv_t[] = {
		{'c', p_char}, {'s', p_string}, {'%', p_percent},
		{'i', p_int}, {'d', p_int}, {'b', p_binary},
		{'u', p_unsigned}, {'o', p_octal}, {'x', p_hexadecimal},
		{'X', p_hexa_upper}, {'p', p_pointer}, {'S', p_non_printable},
		{'r', p_reverse}, {'R', p_rot13string}, {'\0', NULL}
	};
	for (i = 0; conv_t[i].con != '\0'; i++)
		if (con[*ind] == conv_t[i].con)
			return (conv_t[i].fn(list, buff, flags, wid, pre, size));

	if (conv_t[i].con == '\0')
	{
		if (con[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (con[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (wid)
		{
			--(*ind);
			while (con[*ind] != ' ' && con[*ind] != '%')
				--(*ind);
			if (con[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &con[*ind], 1);
		return (len);
	}
	return (ted);
}
