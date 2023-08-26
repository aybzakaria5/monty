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


/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: the stack
 * @line_number: the number of line
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack by
 * the top element of the stack.
 * @stack: the stack
 * @line_number: the number of line
*/
void _div(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}


/**
 * mul - multiplies the second top element of the stack with the
 * top element of the stack
 * @stack: the stack
 * @line_number: the number of line
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}


 /**
  * mod - a fucntion that calculates the mod of a an elemnt to the other
  * @stack: the stack
  * @line_number: the number of line
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
