#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: the number of line
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->n = (*stack)->n + (*stack)->next->n;
	if ((*stack)->next->next)
	{
		(*stack)->next->next->prev = (*stack);
		(*stack)->next = (*stack)->next->next;
	}
	else
	{
		(*stack)->next = NULL;
	}
	free(temp);
}
