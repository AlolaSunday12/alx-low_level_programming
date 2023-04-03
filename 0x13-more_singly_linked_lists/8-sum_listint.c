#include "lists.h"
#include <stdio.h>

/**
 * sum_listint - Function that returns the sum of all the data(n) of a list.
 * @head: A pointer to the address of the head of the list.
 * Return: if the list is empy - 0, otherwise - the sum of all the data.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
