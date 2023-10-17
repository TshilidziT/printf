#include "main.h"

void print_decimal(int number)
{
	char buffer[20];
	int len = snprintf(buffer, sizeof(buffer), "%d", number);
	int size = sizeof(buffer) - 1;

	if (len >= 0 && len < size)
	{
		write(1, buffer, len);
	}
}	

int print_int(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);

	while (*format)
	{
		if (*format != '%' )
		{
			putchar(*format);
			format++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'd':

				case 'i':
					{
					int number = va_arg(arg, int);
					print_decimal(number);
					}
					break;
				default:
					putchar('%');
					putchar(*format);
					break;
			}
			format++;
		}
	}
			va_end(arg);
			return (0);
}
