#include "lists.h"
#include <stdio.h>

/**
 * insert_nodeint_at_index - Function that insert  new node at a given position
 * @head: A pointer to the head of the list
 * @idx: The index of the list
 * @n: The integer for the new node to contain.
 * Return: If the function fails - NULL, otherwise, the address of the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *test, *check = *head;
		unsigned int i;

	test = malloc(sizeof(listint_t));
	if (test == NULL)
		return (NULL);

	test->n = n;

	if (idx == 0)
	{
		test->next = check;
		*head = test;
		return (test);
	}

	for (i = 0; i < (idx - 1); i++)
	{
		if (check == NULL || check->next == NULL)
			return (NULL);

		check = check->next;
	}

	test->next = check->next;
	check->next = test;

	return (test);
}
