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
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);


	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += printf("%%", va_arg(args, char *));

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
	va_end(args);

	return (count);
}
