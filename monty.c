#include "monty.h"
/**
 * main - the main funcion entry point
 * @argc: the argument counter
 * @argv: the argument value
 *
 * Return: always 0
*/

int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		open_file(&head, argv[1]);
	}
	if (head)
		free_stackt(head);

	return (0);
}
