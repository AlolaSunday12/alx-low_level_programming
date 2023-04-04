#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - counts the number of unique nodes in a looped.
 * @head: Apointer to the address of the head of the linked lis.
 * Return: if the list is not looped - 0, otherwise the number of
 * unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *bold, *clear;
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
 * print_listint_safe - prints a listint safely.
 * @head: A pointer to the head of the lis.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t str, new = 0;

	str = looped_listint_len(head);

	if (str == 0)
	{
		for (; head != NULL; str++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (new = 0; new < str; new++)
		{
			printf("[%p} %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p} %d\n", (void *)head, head->n);
	}

	return (str);
}
