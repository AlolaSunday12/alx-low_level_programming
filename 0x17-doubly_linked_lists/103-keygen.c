#include <stdio.h>
#include <string.h>

/**
 * generateKey - function that generate password
 * @username: name
 * @key: the key password
 * Return: 0
 */
void generateKey(const char *username, char *key)
{
	sprintf(key, "%s_key", username);
}

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char username[100];
	char key[100];

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}
	strcpy(username, argv[1]);
	generateKey(username, key);
	printf("%s\n", key);
	return (0);
}
