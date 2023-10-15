#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * _printf - function that produces output accoring to a format.
 * @format: character string
 * Return: count
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list arg;
	int n = snprintf(setbuffer, sizeof(setbuffer), "%d", value);

	va_start(arg, format);

	if (format == NULL || format[0] == '\0')
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			write(1, "[", 1)
			count++;	
			switch (format[i])
				{
				case 'c':
					char c = va_arg(arg, int);
					write(1, "&c", c);
					count++;
					break;
				case 's':
					char *str = va_arg(arg, char *)
					int len = strlen(str);	
					write(1, str, len);
					count += len;
					break;
				
				case 'd':
				case 'i':
				case 'u':
				case 'o':
				case 'x':
				case 'X':
				case 'p':
				
					int value = va_arg(arg, int);
					char buffer [64];
					write(1, buffer, n);
					count += n;
					break;
		
				default:
					write(1, "r", 1);
					count++;
				}
		}
		else
		{
			write(1 , &format[i], 1);
			count++;

		}
	}
	va_end(arg);

	return (count);
}
