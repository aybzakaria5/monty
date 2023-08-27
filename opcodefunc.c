#include "monty.h"


/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: the line number
 *
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}

	if (data.args[1] && alldigit(data.args[1]))
	{
		new->n = atoi(data.args[1]);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new->next = NULL;
	}
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	new->prev = NULL;
	*stack = new;
	if (strcmp(data.mode, "queue") == 0)
	{
		rotl(stack, line_number);
	}
}



/**
 * pall - prints all the values on the stack, starting
 * from the top of the stack.
 * @stack: the stack
 * @line_number: the line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}



/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: the line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*stack)->next == NULL)
		{
			free(temp);
			*stack = NULL;
		}
		else
		{
			(*stack)->next->prev = NULL;
			*stack = (*stack)->next;
			free(temp);
		}
	}
}

/**
 * pint - prints the value at the top of the stack,
 * followed by a new line
 * @stack: the stack
 * @line_number: the line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", ((*stack)->n));
}


/**
 * swap - a fucntion that swaps the tow top nodes in the stack
 * @stack: the stack with its data
 * @line_number: the line number of the operation
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	top1 = *stack;
	top2 = (*stack)->next;

	top1->prev = top2;
	top1->next = top2->next;
	top2->prev = NULL;
	top2->next = top1;
	if (*stack == top1)
	{
		*stack = top2;
	}
}
