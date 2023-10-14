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
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			if (format[i] == '%')
			{
				i++;
				switch (format[i])
				{
					case 'c':
						count += fprintf(stdout, "%c", va_arg(args, int));
						break;
					case 's':
						count += fprintf(stdout, "%s", va_arg(args, char *));
						break;

					default:
						putchar('%');
						putchar(format[i]);
						count += 2;
						break;
				}

				format++;
			}
		}
	}
	va_end(args);
	return (count);
}
