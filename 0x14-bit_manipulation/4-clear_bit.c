#include "main.h"

/**
 * clear_bit - function
 * @n: number of search.
 * @index: index of the bit.
 * Return: on succes - 1, on failure - -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n = (~(1UL << index) & *n);

	return (1);
}
