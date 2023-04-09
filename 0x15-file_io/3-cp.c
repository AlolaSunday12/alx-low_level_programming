#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Alloctaes 1024 bytes for a bug.
 * @file: The name of the file bug is storing chars for.
 * Return: A pointer to the newly allocated bug.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - close file description.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int a;

	a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another file.
 * @argc: The number ofarguments supplied to th program.
 * @argv: An array of pointers to the arguments.
 * Return: 0n success - 0.
 *
 * Description: if the argument count is incorrect - exit code 97
 * if file_from does not exist or cannot be read - exit code 98
 * if file-to cannot be created or written to - exit code 99
 * if file_to or file_from cannot be close - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, i, j;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	i = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || i == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		j = write(to, buffer, i);
		if (to == -1 || j == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		i = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (i > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
