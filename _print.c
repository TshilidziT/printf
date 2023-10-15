#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * _printf - function that produces output accoring to a format.
 * @format: character string
 * Return: count
 */

int _printf(const char *format, ...)
{
	int i, count = 0;
	char c;
	char *str;
	va_list arg;

	va_start(arg, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

			switch (format[i])
			{
				case 'c':
					c = va_arg(arg, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(arg, char *);
					if (str != NULL)
					{
						write(1, str, strlen(str));
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, &format[i - 1], 1);
					write(1, &format[i], 1);
					count += 2;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(arg);

	return (count);
}
