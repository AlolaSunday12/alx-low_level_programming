#include "lists.h"
#include <stdio.h>

/**
 * add_nodeint_end - Write a function that add a new node at the end of
 * teh list.
 * @head: A pointer to the address of the head of the list.
 * @n: The integer for the new node to contain.
 * Return: if fails - NULL, otherwise, the address of the new element.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *i, *j;

	i = malloc(sizeof(listint_t));
	if (i == NULL)
		return (NULL);

	i->n = n;
	i->next = NULL;

	if (*head == NULL)
		*head = i;

	else
	{
		j = *head;
		while (j->next != NULL)
			j = j->next;
		j->next = i;
	}
	return (*head);
}
