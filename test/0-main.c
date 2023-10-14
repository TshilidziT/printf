#include <stdio.h>

/**
 * main - entry point
 *
 * Return: 0
 */

int main(void)
{
	char *format = "ALX is %s";
	char *letter = "%c";

	printf(format, "great");
	printf(letter, "A");

	printf("\n");

	return (0);

}
