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
