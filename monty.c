#include "monty.h"

int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
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
