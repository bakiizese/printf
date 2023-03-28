#include "main.h"

int flags_g(const char *format, int *i)
{
	int j, id;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (id = *i + 1; format[id] != '\0'; id++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[id] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = id - 1;
	return (flags);
}
