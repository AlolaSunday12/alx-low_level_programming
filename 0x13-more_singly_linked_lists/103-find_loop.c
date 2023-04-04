#include "lists.h"

/**
 * find_listint_loop - fint the loop in a linked list.
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *new = head;
	listint_t *old = head;

	if (!head)
		return (NULL);

	while (new && old && old->next)
	{
		old = old->next;
		new = new->next;
		if (old == new)
		{
			new = head;
			while (new != old)
			{
				new = new->next;
				old = old->next;
			}
			return (old);
		}
	}
	return (NULL);
}
