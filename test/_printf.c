#include "main.h"
/**
 * _printf - produce output according to function.
 * @format: character string
 * return: count
 */

int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int i, count = 0;
	va_list arg;

	va_start(arg, format);
=======

	int count = 0;
	va_list args;
>>>>>>> a1caf14019c8e933f923cff46a94a6cd67fa53c5

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

<<<<<<< HEAD
	for (i = 0; format[i] != '\0'; i++)
	{	break;
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
				case '%':
					count += printf("%%", va_arg(arg, char *));

					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
					break;
			}
=======
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
>>>>>>> a1caf14019c8e933f923cff46a94a6cd67fa53c5
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
	va_end(arg);

	return (count);
}
