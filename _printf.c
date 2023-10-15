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
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			break;

			if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			if (*format == 's')
			{
				const char *str = va_arg(args, const char*);

				write(1, str, strlen(str));
				count++;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
		}

		format++;
	}
	va_end(args);

	return (count);
}
