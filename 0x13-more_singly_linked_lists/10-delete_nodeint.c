#include "lists.h"
#include <stdio.h>

/**
 * delete_nodeint_at_index - Function that delete the node at index linked list
 * @head: A pointer to the address of the head of the list
 * @index: The index of the node to be deleted - indices start at 0.
 *
 * Return: on success - 1, on failure - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *i, *j = *head;
	unsigned int k;

	if (j == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(j);
		return (1);
	}

	for (k = 0; k < (index - 1); k++)
	{
		if (j->next == NULL)
			return (-1);

		j = j->next;
	}

	i = j->next;
	j->next = i->next;
	free(i);
	return (1);
}
