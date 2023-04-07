#include "main.h"

/**
 * set_bit - Funtion that se the value of a bit.
 * @n: number of search
 * @index: index of the bit
 * Return: on success - 1, on failures - -1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
	{
		return (-1);
	}

	*n = ((1UL << index) | *n);
	return (1);
}
