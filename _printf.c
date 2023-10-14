#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
/**
 * _printf - produce output according to function.
 * @format: character string
 * return: count
 */

int _printf(const char *format, ...)
{

	int count;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, const char*);

				while (*str)
				{

					putchar(*str);
					str++;
					count++;
				}
			}
		}
		else
		{

			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);

	return (count);
}
