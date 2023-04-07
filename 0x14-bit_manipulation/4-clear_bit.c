#include "main.h"

/**
 * clear_bit - Function that sets the value of a bit to 0 at a give index.
 * @n: number of search
 * @index: index of the bit
 * Return: on success - 1, on failures - -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
	{
		return (-1);
	}

	*n = (~(1UL << index) & *n);

	return (1);
}
