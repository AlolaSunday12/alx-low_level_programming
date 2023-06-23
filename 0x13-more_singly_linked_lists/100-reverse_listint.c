#include "lists.h"
#include <stdio.h>

/**
 * reverse_listint - Write a function that reverse a linked list.
 * @head: A pointer to the address of the head of the list.
 * Return: A pointer to the first noe of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *future, *past;

	if (head == NULL || *head == NULL)
		return (NULL);

	past = NULL;

	while ((*head)->next != NULL)
	{
		future = (*head)->next;
		(*head)->next = past;
		past = *head;
		*head = future;
	}

	(*head)->next = past;

	return (*head);
}
