#include "main.h"

int writing_char(char c, char buff[], int flags, int wid, int pre, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSE(pre);
	UNUSE(size);

	if (flags & ZERO)
		padd = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (wid > 1)
	{
		buff[SIZE_B - 1] = '\0';
		for (i = 0; i < wid - 1; i++)
			buff[SIZE_B - i - 2] = padd;

		if (flags & MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[SIZE_B - i - 1], wid - 1));
		else
			return (write(1, &buff[SIZE_B - i - 1], wid - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

int writing_number(int is_neg, int ind, char buff[], int flags, int wid, int pre, int size)
{
	int length = SIZE_B - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSE(size);

	if ((flags & ZERO) && !(flags & MINUS))
		padd = '0';
	if (is_neg)
		extra_ch = '-';
	else if (flags & PLUS)
		extra_ch = '+';
	else if (flags & SPACE)
		extra_ch = ' ';

	return (writing_num(ind, buff, flags, wid, pre,
		length, padd, extra_ch));
}

int writing_num(int ind, char buff[], int flags, int wid, int pre, int len, char dep, char exe)
{
	int i, dep_srt = 1;

	if (pre == 0 && ind == SIZE_B - 2 && buff[ind] == '0' && wid == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (pre == 0 && ind == SIZE_B - 2 && buff[ind] == '0')
		buff[ind] = dep = ' '; /* width is displayed with padding ' ' */
	if (pre > 0 && pre < len)
		dep = ' ';
	while (pre > len)
		buff[--ind] = '0', len++;
	if (exe != 0)
		len++;
	if (wid > len)
	{
		for (i = 1; i < wid - len + 1; i++)
			buff[i] = dep;
		buff[i] = '\0';
		if (flags & MINUS && dep == ' ')/* Asign extra char to left of buffer */
		{
			if (exe)
				buff[--ind] = exe;
			return (write(1, &buff[ind], len) + write(1, &buff[1], i - 1));
		}
		else if (!(flags & MINUS) && dep == ' ')/* extra char to left of buff */
		{
			if (exe)
				buff[--ind] = exe;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], len));
		}
		else if (!(flags & MINUS) && dep == '0')/* extra char to left of padd */
		{
			if (exe)
				buff[--dep_srt] = exe;
			return (write(1, &buff[dep_srt], i - dep_srt) +
				write(1, &buff[ind], len - (1 - dep_srt)));
		}
	}
	if (exe)
		buff[--ind] = exe;
	return (write(1, &buff[ind], len));
}

int writing_unsigned(int is_neg, int id, char buff[], int flags, int wid, int pre, int size)
{
    char dep = ' ';
	int len = SIZE_B - id - 1, i = 0;

	UNUSE(is_neg);
	UNUSE(size);
	if (pre == 0 && id == SIZE_B - 2 && buff[id] == '0')
		return (0);
	if (pre > 0 && pre < len)
		dep = ' ';
	while (pre > len)
	{
		buff[--id] = '0';
		len++;
	}
	if ((flags & ZERO) && !(flags & MINUS))
		dep = '0';
	if (wid > len)
	{
		for (i = 0; i < wid - len; i++)
			buff[i] = dep;
		buff[i] = '\0';
		if (flags & MINUS)
		{
			return (write(1, &buff[id], len) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[id], len));
		}
	}
	return (write(1, &buff[id], len));
}

int writing_pointer(char buff[], int id, int len, int wid, int flags, char dep, char exe, int dep_srt)
{
	int i;

	if (wid > len)
	{
		for (i = 3; i < wid - len + 3; i++)
			buff[i] = dep;
		buff[i] = '\0';
		if (flags & MINUS && dep == ' ')/* Asign extra char to left of buffer */
		{
			buff[--id] = 'x';
			buff[--id] = '0';
			if (exe)
				buff[--id] = dep;
			return (write(1, &buff[id], len) + write(1, &buff[3], i - 3));
		}
		else if (!(flags & MINUS) && dep == ' ')/* extra char to left of buffer */
		{
			buff[--id] = 'x';
			buff[--id] = '0';
			if (exe)
				buff[--id] = exe;
			return (write(1, &buff[3], i - 3) + write(1, &buff[id], len));
		}
		else if (!(flags & MINUS) && dep == '0')/* extra char to left of padd */
		{
			if (exe)
				buff[--dep_srt] = exe;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[dep_srt], i - dep_srt) +
				write(1, &buff[id], len - (1 - dep_srt) - 2));
		}
	}
	buff[--id] = 'x';
	buff[--id] = '0';
	if (exe)
		buff[--id] = exe;
	return (write(1, &buff[id], SIZE_B - id - 1));
}
