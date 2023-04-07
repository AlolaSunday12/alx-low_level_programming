#include "main.h"

/**
 * get_bit - Function that return the value of a bit.
 * @n: number to search
 * @index: index of the bit
 * Return: value of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int i;

	if (index > 63)
		return (-1);
	i = (n >> index) & 1;

	return (i);
}
