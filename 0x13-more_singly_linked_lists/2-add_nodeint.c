#include "lists.h"
#include <stdio.h>

/**
 * add_nodeint - Write a function that add new node at the begining of a list.
 * @head: A pointer to the adress of the head of the list.
 * @n: The integer for the new node to contain.
 * Return: if fails - NULL, otherwise the adress of the new element.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *i;

	i = malloc(sizeof(listint_t));
	if (i == NULL)
		return (NULL);

	i->n = n;
	i->next = *head;

	*head = i;

	return (i);
}
