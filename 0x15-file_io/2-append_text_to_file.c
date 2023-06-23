#include "main.h"

/**
 * append_text_to_file - append file at teh end of the file.
 * @filename: A pointer to the append file.
 * @text_content: Number of text content.
 * Return: on succes - 1,otherwise - -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, b, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	a = open(filename, O_WRONLY | O_APPEND);
	if (a == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	b = write(a, text_content, len);
	if (b == -1)
	{
		return (-1);
	}

	close(a);
	return (1);
}
