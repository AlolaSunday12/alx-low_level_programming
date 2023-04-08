#include "main.h"

/**
 * get_endianness - Function that checks the endianness.
 * Return: big - 0, little - 1
 */
int get_endianness(void)
{
	unsigned int bug = 0x03;
	char *c = (char *) &bug;

	return (*c);
}
