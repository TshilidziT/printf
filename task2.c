#include "main.h"
#include <unistd.h>

/**
 * _printBinary - prints binary number
 * return: count
 */

int _printBinary(unsigned int x, const char *conversionSpecifier)
{
	int y;
	int count = 0;

	if (strcmp(conversionSpecifier, "%b") == 0)
	{
		for (y  = 31; y >= 0; y--)
		{
			if ((x >> y) & 1)
			{
				write(1, "1", 1);
			}
			else
			{	
				write(1, "0", 1);
			}
			count++;
		}
		return (count);
	}
	return (-1);
}
