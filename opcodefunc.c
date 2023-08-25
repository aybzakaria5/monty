#include "monty.h"

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
	(void)stack;
	(void)line_number;
	printf("I am popping the stack\n");
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
