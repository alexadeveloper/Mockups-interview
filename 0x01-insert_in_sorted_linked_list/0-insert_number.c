#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
  *insert_node- insert a node
  *@head: the pointer at the beggining
  *@number: position
  *Return: the address of the new code
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *copy;

	copy = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL || copy->n > new->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	while (copy->next != NULL)
	{
		if ((copy->next->n > new->n && copy->n < new->n))
		{
			new->next = copy->next;
			copy->next = new;
			return (new);
		}
		if (new->n == copy->n)
		{
			new->next = copy->next;
			copy->next = new;
			return (new);
		}
		copy = copy->next;
	}
	new->next = copy->next;
	copy->next = new;
	return (new);
}