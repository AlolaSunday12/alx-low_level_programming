#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);
/**
 * create_buffer - Allocates 1024 bytes.
 * @file: The name of the file buffer is storing chars for.
 * Return: Apointer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: cant't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}
/**
 * close_file - closes file descriptors.
 * @fd: File descriptor to be closed.
 */
void close_file(int fd)
{
	int i;

	i = close(fd);
	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the to the arguments.
 * Return: 0 on success.
 *
 * Description: if the arguments count is inorrect - exit code 97.
 * if file-from does not exist or cannot be read - exit code 98.
 * if file_to caannot be created or written to - exit code 99.
 * if file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, n, m;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	n = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || n == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		m = write(to, buffer, n);
		if (to == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		n = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (n > 0);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}
