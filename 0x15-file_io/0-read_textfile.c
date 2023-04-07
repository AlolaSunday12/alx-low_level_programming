#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Function that read a textfile and print it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 *
 * Return: if the function fails or filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t a, b, c;
	char *bug;

	if (filename == NULL)
		return (0);

	bug = malloc(sizeof(char) * letters);
	if (bug == NULL)
		return (0);

	a = open(filename, O_RDONLY);
	b = read(a, bug, letters);
	c = write(STDOUT_FILENO, bug, b);

	if (a == -1 || b == -1 || c == -1 || c != b)
	{
		free(bug);
		return (0);
	}

	free(bug);
	close(a);

	return (c);
}
