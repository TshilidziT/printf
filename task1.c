#include "main.h"

/**
 * int_to_str- Converts a decimal integer to a string
 * @number: number of decimal integers
 * @Return: A pointer to the string representation of the
 * number or Null if memory allocation failed
 */

char *int_to_str(int number)
{
	char *buffer = malloc(12);
	char *ptr = buffer + 11;
	int sign = 1;

	if (buffer == NULL)
	{
		return (NULL);
	}

	*ptr = '\0';
	if (number == 0)
	{
	*(--ptr) = '0';
	return (ptr);
	}

	if (number < 0)
	{
	number = -number;
	sign = -1;
	}
	while (number > 0)
	{
		char digit = '0' + (number % 10);

		*(--ptr) = digit;
		number /= 10;
	}
	if (sign < 0)
	{
		*(--ptr) = '-';
	}
	return (ptr);
}

void print_str(char *str)

{
	while (*str)
	{
		putchar(*str);
		str++;
	}
}

void print_decimal(char specifier, int number)
	{
	if (specifier == 'd' || specifier == 'i')
	{
		char *str = int_to_str(number);

		if (str != NULL)
		{
			print_str(str);
			free(str);
		}
		else
		{
			print_str("Memoryallocationerror\n");
		}

	}
	else
	{
		print_str("Invalidspecifier:");
		putchar(specifier);
		putchar('\n');

	}
	}

void my_printf(char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			format++;
		}
		else
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int number = va_arg(args, int);

				print_decimal(*format, number);
				format++;
			}
			else
			{
				print_str("Invalidformat:");
				putchar(*format);
				putchar('\n');
				break;
			}
		}
	}
}
