#include "main.h"
/**
 * my_printf - prints %i and %d.
 * @format: string
 * Return: buffer
 */
char *my_printf(const char *format, ...)
{
	va_list args;
	char *buffer; 
	int buffer_index = 0;

	va_start(args, format);
	buffer = (char *)malloc(12);

	if (buffer == NULL)
	{
		return (NULL);
	}
	while (*format != '\0')
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int number = va_arg(args, int);

			if (number < 0)
			{
				buffer[buffer_index++] = '-';
				number = -number;
			}
			while (number > 0)
			{
				buffer[buffer_index++] = '0' + (number % 10);
				number /= 10;
			}
			format += 2;
		}
		else
		{
			buffer[buffer_index++] = *format;
			format++;
		}
	}
	buffer[buffer_index++] = '\0';
	va_end(args);
	free(buffer);
	return (buffer);
}
