#ifndef MONTY_H
#define MONTY_H


#define _POSIX_C_SOURCE 200809L
#define SIZE 13
#define DELIM "\t\n "


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct data_s - list representing data needed in different functions
 * @args: array of parsed arguments in each line
 * @file: input file
 * @line: buffer for storing a line of the input file
 *
 * Description: list representing data needed in different functions
 * of the program
*/
typedef struct data_s
{
	char *args[2];
	FILE *file;
	char *line;
} data_t;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


extern data_t data;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Functions to handle the monty file */
void open_file(stack_t **stack, char *filename);
void read_file(stack_t **stack);
void process_line(stack_t **stack, unsigned int lines_count);


/* Functions to handle the opcode instructions */
int alldigit(char *str);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
/**void swap_2(stack_t **stack, unsigned int line_number);**/
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);


/* Functions to handle the stack operations */
void free_stackt(stack_t *head);

#endif /* MONTY_H */
