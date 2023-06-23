#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that read a text file and prints it POSIX stdout.
 * @filename: Apointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 * Return: if the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t a, b, c;
	char *bug;

	if (filename == NULL)
	{
		return (0);
	}
	bug = malloc(sizeof(char) * letters);
	if (bug == NULL)
	{
		return (0);
	}
		a = open(filename, O_RDONLY);
		if (a == -1)
		{
			return (0);
		}
		b = read(a, bug, letters);
		if (b == -1)
		{
			return (0);
		}
		c = write(STDOUT_FILENO, bug, b);
		if (c == -1 || c != b)
		{
			return (0);
		}

		free(bug);
		close(a);

		return (c);
}
