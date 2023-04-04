#include "lists.h"

/**
 * free_listint_safe - frees a link list.
 * @h: A pointer to the address of the head of nthe linked list.
 * Return: number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t str = 0;
	int diff;
	listint_t *new;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if  (diff > 0)
		{
			new = (*h)->next;
			free(*h);
			*h = new;
			str++;
		}

		else
		{
			free(*h);
			*h = NULL;
			str++;

			break;
		}
	}
	*h = NULL;
	return (str);
}
