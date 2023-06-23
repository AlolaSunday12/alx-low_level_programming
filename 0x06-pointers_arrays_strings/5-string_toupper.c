#include "main.h"

/**
 * string_toupper - Changess all lowercase letters
 * of a string to uppercase.
 * @str: The string to be change.
 * Return: Apointer to be chnaged string.
 *
 */

char *string_toupper(char *str)

{
	int index = 0;

	while (str[index])
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] -= 32;
		index++;
	}
	return (str);
}
