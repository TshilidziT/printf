#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
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

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += printf("%c", va_arg(arg, int));
					break;
				case 's':
					count += printf("%s", va_arg(arg, char *));
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;

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
