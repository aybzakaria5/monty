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


/**
 * nop - a function that does nothing
 * @stack: the stack
 * @line_number: the line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * alldigit - check if a string contains only digits
 * @str: the string to check
 *
 * Return: 1 if all digit
 * 0 if not
*/
int alldigit(char *str)
{
	int l = strlen(str), i;

	for (i = 0; i < l; i++)
	{
		if (str[0] == '-')
			continue;
		if (isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}


/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @stack: the stack
 * @line_number: the number of line
*/
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.mode = "stack";
}


/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: the stack
 * @line_number: the number of line
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.mode = "queue";
}
