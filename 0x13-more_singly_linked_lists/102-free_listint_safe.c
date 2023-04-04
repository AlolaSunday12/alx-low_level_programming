#include "lists.h"
#include <stdio.h>

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - counts the number of unique nodes
 * @head: A pointer to the head of the linked list
 * Return: If the list is not looped - o, otherwise the number of
 * unique nodes in the list.
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *bold, *clear;
	size_t cloud = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	bold = head->next;
	clear = (head->next)->next;

	while (clear)
	{
		if (bold == clear)
		{
			bold = head;
			while (bold != clear)
			{
				cloud++;
				bold = bold->next;
				clear = clear->next;
			}

			bold = bold->next;
			while (bold != clear)
			{
				cloud++;
				bold = bold->next;
			}

			return (cloud);
		}

		bold = bold->next;
		clear = (clear->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - free a listint list safely.
 * @h: A pointer to the address of the head of the linked list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *cat;
	size_t min, len;

	min = looped_listint_count(*h);

	if (min == 0)
	{
		for (; h != NULL && *h != NULL; min++)
		{
			cat = (*h)->next;
			free(*h);
			*h = cat;
		}
	}

	else
	{
		for (len = 0; len < min; len++)
		{
			cat = (*h)->next;
			free(*h);
			*h = cat;
		}

		*h = NULL;
	}

	h = NULL;

	return (min);
}
