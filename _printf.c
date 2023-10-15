#include "main.h"
/**
 * _printf - produce output according to function.
 * @format: character string
 * return: count
 */

int _printf(const char *format, ...)
{

	int count = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
		{
			break;
		}
		}
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				putchar(c);
				count++;
			}
			if (*format == 's')
			{
				const char *str = va_arg(args, const char*);

				while (*str)
				{

					putchar(*str);
					str++;
					count++;
				}
			if (*format == '%')
			{
				putchar('%');
				count++;
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
