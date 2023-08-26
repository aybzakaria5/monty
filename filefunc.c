#include "monty.h"

data_t data = {{NULL, NULL}, NULL, NULL};

/**
 * process_data - a function to finds and excutes the opcode if existed
 * @stack: the stack
 * @lines_count: the number of line
*/
void process_data(stack_t **stack, unsigned int lines_count)
{
	int i, found = 0;
	instruction_t opcodes[SIZE] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod}
	};

	data.args[0] = strtok(data.line, DELIM);
	data.args[1] = strtok(NULL, DELIM);
	if (!(data.args[0]) || data.args[0][0] == '#')
	{
		found = 1;
	}
	else
	{
		for (i = 0; i < SIZE; i++)
		{
			if (strcmp(data.args[0], opcodes[i].opcode) == 0)
			{
				found = 1;
				opcodes[i].f(stack, lines_count);
			}
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lines_count, data.args[0]);
		fclose(data.file);
		free(data.line);
		if (*stack)
			free_stackt(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * read_file - a fucntion that reads the file and send its
 *informations to the process_data function
 *@stack: the stack
 */
void read_file(stack_t **stack)
{
	size_t bufsize = 0;
	ssize_t chars_read;
	unsigned int lines_count = 0;

	while ((chars_read = getline(&(data.line), &bufsize, data.file)) != -1)
	{
		lines_count++;
		process_data(stack, lines_count);
	}
	if (data.line)
		free(data.line);
}


/**
 * open_file - a function that opens a file if exists
 * @stack: the stack
 * @filename: the name of the file
*/
void open_file(stack_t **stack, char *filename)
{
	data.file =  fopen(filename, "r");

	if (!(data.file))
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	else
	{
		read_file(stack);
	}
	fclose(data.file);
}
