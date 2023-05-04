#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - function that convert a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and  1.
 * Return: converted number, 0 if there is one or more chars in the string b
 * that is not 0 or 1, b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	int bit;
	unsigned int num = 0;

	if (b == NULL)
		return (0);

	for (bit = 0; b[bit] != '\0'; bit++)
	{
		if (b[bit] != '0' && b[bit] != '1')
			return (0);

		num = num * 2 + (b[bit] - '0');
	}

	return (num);
}
