#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array to search in
 * @size: siz eof the array
 * @cmp: pointer to the comparing function
 *
 * Return: index of the first element for which the cmp function does not
 * return 0, or -1 if no natch is found or size is negative.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if  (array && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}
