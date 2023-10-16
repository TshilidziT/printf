#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - function that produces output accoring to a format.
 * @format: character string
 * Return: count
 */

int _printf(const char *format, ...)
{
	int i, count = 0;
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
					count += printf("%c", va_arg(arg, int));
					break;
				case 's':
					count += printf("%s", va_arg(arg, char *));
					break;
				case '%':
					count += printf("%%", va_arg(arg, char *));

					break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;

		}

	}
	va_end(arg);

	return (count);
}