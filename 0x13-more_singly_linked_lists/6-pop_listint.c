#include "lists.h"
#include <stdio.h>

/**
 * pop_listint - Write a function that delete the head node of a linked list,
 * and returns the head node data(n).
 * @head: A pointer to the address of the head of the list.
 * Return: If the linked list is empty - 0, otherwise
 * The head node data(n).
 */
int pop_listint(listint_t **head)
{
	listint_t *str;
	int i;

	if (*head == NULL)
		return (0);

	str = *head;
	i = (*head)->n;
	*head = (*head)->next;

	free(str);

	return (i);
}
