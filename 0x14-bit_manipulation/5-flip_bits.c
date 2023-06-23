#include "main.h"

/**
 * flip_bits - function that returns number of bits.
 * @n: first number.
 * @m: second number.
 * Return: number of bit.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int result = 0;
	unsigned long int bug = n ^ m;

	while (bug)
	{
		result += bug & 1;
		bug >>= 1;
	}

	return (result);
}
