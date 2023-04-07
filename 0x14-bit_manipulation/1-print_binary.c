#include <stdio.h>

/**
 * print_binary - Function that print the binary representation of a number.
 * @n: Number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int new, len = 0;
	unsigned long int str;

	for (new = 63; new >= 0; new--)
	{
		str = n >> new;

		if (str & 1)
		{
			putchar('1');
			len++;

		}
		else if (len)
			putchar('0');
	}
	if (!len)
		putchar('0');
}
