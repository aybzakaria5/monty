#include "monty.h"

/**
 * free_stackt - frees a dlistint_t list
 * @head: pointer to first node
 *
*/
void free_stackt(stack_t *head)
{
	stack_t *current = head;

	while (head)
	{
		current = current->next;
		free(head);
		head = current;
	}
}
