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
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(*format);
			coun++;
		}
		else
		{
			if (format[i] == '%')
			{
				i++;
				while (format[i])
				{
					if (format[i] == 'c')
						count += fprintf(stdout, "%c", va_arg(arg, int));
					else if (format[i] == 's')
						count += fprintf(stdout, "%s", va_arg(arg, char *));
							putchar('%');
							putchar(format[i]);
							count += 2;
				}

				format++;
			}
		}
	}
	va_end(arg);
	return (count);
}
