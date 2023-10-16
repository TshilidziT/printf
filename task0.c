#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: character string.
 * Return: count.
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(arg);
				return (-1);
			}
			switch (format[i])
			{
				case 'c':
					count += handleChar(va_arg(arg, int));
					break;
				case 's':
					count += handleString(va_arg(arg, char *));
					break;
				case '%':
					count += handlePercent();
					break;
				default:
					count += handleDefault(format, i);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(arg);
	return (count);
}
/**
 * handleString - handles a string.
 * @str: string
 * Return: The number of characters in string or 0 if null.
 */
int handleString(char *str)
{
	if (str != NULL)
	{
		size_t length = strlen(str);

		write(1, str, length);
		return ((int)length);
	}
	return (0);
}
/**
 * handlePercent - handles the percent.
 * Return: always 1.
 */
int handlePercent(void)
{
	write(1, "%", 1);
	return (1);
}
/**
 * handleChar - handles a character
 * @c: letter to be printed.
 * Return: 1 success
 */
int handleChar(int c)
{
	write(1, &c, 1);
	return (1);
}
/**
 * handleDefault - handles unknown specifiers.
 * @format: the string
 * @i: index
 * Return: 2 success.
 */
int handleDefault(const char *format, int i)
{
	write(1, &format[i - 1], 1);
	write(1, &format[i], 1);
	return (2);
}
