#include <stdio.h>

/**
 * main - entry point
 *
 * Return: 0
 */

int main(void)
{
	char *format = "ALX is %s\n";
	char *letter = "A";

	printf(format, "great");
	printf("%s\n", letter);
	printf("%%\n");


	return (0);

}
