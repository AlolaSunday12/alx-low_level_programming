#include "main.h"

/**
 * create_file - function that creates a file to create.
 * @filename: A pointer to the name of the file to create.
 * @text_content: a pointer to a string to write to the file.
 * Return: if function fails - -1, otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int a, b, str = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	a = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (a == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (str = 0; text_content[str];)
			str++;
	}
	b = write(a, text_content, str);
	if (b == -1)
	{
		return (-1);
	}

	close(a);
	return (1);
}
