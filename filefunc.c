#include "monty.h"

data_t data = {{NULL, NULL}, NULL, NULL};

/**
 * process_data.line -
*/
void process_data(stack_t **stack, unsigned int lines_count)
{
	int i, found = 0;
	instruction_t opcodes[SIZE] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint}
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
		printf("L%d: unknown instruction %s\n", lines_count, data.args[0]);
		fclose(data.file);
		free(data.line);
		if (*stack)
			free_stackt(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * read_file -
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
 * open_file -
*/
void open_file(stack_t **stack, char *filename)
{
	data.file =  fopen(filename, "r");

	if (!(data.file))
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	else
	{
		read_file(stack);
	}
	fclose(data.file);
}
