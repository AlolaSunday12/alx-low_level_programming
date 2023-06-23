#include "main.h"

/**
 * get_endianness - get
 *
 * Return: big - 0, little - 1
 */
int get_endianness(void)
{
	unsigned int bug = 1;
	int *i = (int *) &bug;

	if (*i)
		return (1);
	else
		return (0);
}
