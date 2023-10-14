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
<<<<<<< HEAD

	int count;
	va_list args;
=======
	int i, count = 0;
	va_list args;

	va_start(args, format);
>>>>>>> ff076e3b8a8852ff8e16873df5f5d7d15b930f00

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
<<<<<<< HEAD
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
=======
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
>>>>>>> ff076e3b8a8852ff8e16873df5f5d7d15b930f00
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
