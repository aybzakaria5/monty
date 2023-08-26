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
 * swap - a function that swaps the top tow elemnets
 * 
 * 
*/

/**void swap(stack_t **stack, unsigned int line_number )
{	
	int temp;
	(void)line_number;

	if ((*stack)->n == (*stack)->next->n)
	{
		printf("it's equale no need to convert");
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
**/

/**
 * swap - a fucntion that swaps the tow top nodes in the stack
 * @stack: the stack with its data
 * @line_number: the line number of the operation
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;
	if ( !stack || !(*stack) || !(*stack)->next)
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