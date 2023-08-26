#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: the stack
 * @line_number: the number of line
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int d;

	if (!(*stack) || !stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	d = (*stack)->n;
	if (d < 65 || (d > 90 && d < 97) || d > 122)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free(data.line);
		free_stackt(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", d);
}


/**
 * pstr - prints the string starting at the top of the stack
 * @stack: the stack
 * @line_number: the number of line
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int d;
	(void)line_number;

	if ((*stack) || stack)
	{
		curr = *stack;
		while (curr)
		{
			d = curr->n;
			if (curr->n == 0)
				break;
			if (d < 65 || (d > 90 && d < 97) || d > 122)
				break;
			printf("%c", d);
			curr = curr->next;
		}
	}
	printf("\n");
}


/**
 * rotr - a fucntion that rotates the stack's elemen from top to last
 *@stack: the stack
 *@line_number: the line number
*/

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;
    stack_t *last = *stack;
	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = top;
    top->prev = last;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}
