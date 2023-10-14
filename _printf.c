#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - function that produces output accoring to a format.
 * @format: character string
 * Return: i
 */

int _printf(const char *format, ...)
{
	int i;
	va_list arg;

	va_start(arg, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printf("%c\n", va_arg(arg, int));
					break;
				case 's':
					printf("%s\n", va_arg(arg, char *));
					break;
			}
		}
		else
		{
			printf("%c\n", format[i]);
		}

	}
	va_end(arg);

	return (i);
}
