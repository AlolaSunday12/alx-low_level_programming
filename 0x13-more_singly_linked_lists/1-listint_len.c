#include "lists.h"
#include <stdio.h>

/**
 * listint_len - Write a function that returns the number of element
 * in a linked list.
 * @h: A pointer to the head of the list_t list.
 * Return: Number of elements in a linked list
 */
size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);
}
