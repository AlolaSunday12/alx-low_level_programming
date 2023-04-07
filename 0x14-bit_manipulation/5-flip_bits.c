#include "main.h"

/**
 * flip_bits - Function that returnsthe number of bits.
 * @n: first number
 * @m: second number
 * Return: number of bit
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int o, tech = 0;
	unsigned long int bug;
	unsigned long int bugger = n ^ m;

	for (o = 63; o >= 0; o--)
	{
		bug = bugger >> o;

		if (bug & 1)
			tech++;
	}

	return (tech);
}
