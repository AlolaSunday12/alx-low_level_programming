#include "lists.h"
#include <stdio.h>

/**
 * free_listint - Write a function that free a list.
 * @head: A pointer to the head of the list to be freed.
 * Return: Return 0 (success)
 */
void free_listint(listint_t *head)
{
	listint_t *str;

	while (head)
	{
		str = head->next;
		free(head);
		head = str;
	}
}
