#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - function that produces output accoring to a format.
 * @format: character string
 * Return: i
 */
int _printf(const char *format, ...)
{
	int i;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printf("%c", va_arg(args, int));
					break;
				case 's':
					printf("%s", va_arg(args, char *));
					break;

				default:
					printf("%%");
					break;
			}

		}
		else
		{

		printf("%c", format[i]);
		}
	}
	va_end(args);
	return (i);
	
}
