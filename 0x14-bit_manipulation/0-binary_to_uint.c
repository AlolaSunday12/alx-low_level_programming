#include "main.h"

/**
 * binary_to_uint - Function that convert a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1.
 *
 * Return: converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1, b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	int new;
	unsigned int value = 0;

	if (!b)
		return (0);
	for (new = 0; b[new]; new++)
	{
		if (b[new] < '0' || b[new] > '1')
			return (0);
		value = 2 * value + (b[new] - '0');
	}
	return (value);
}
