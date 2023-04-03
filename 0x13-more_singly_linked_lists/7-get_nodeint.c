#include "lists.h"
#include <stdio.h>

/**
 * get_nodeint_at_index - Function that returns nth node of a linked list.
 * @head: A pointer to the address of the head of the list.
 * @index: The index of the node
 * Return: If the node does not exist - NULL, otherwise - the located node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}
	return (head);
}
