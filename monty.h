#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INSTRUCTIONS              \
{                           \
	{"push", push},       \
	{"pall", pall},   \
	{"pint", pint},   \
	{"pop", pop},     \
	{"swap", swap},   \
	{"nop", nop},     \
	{"div", my_div},    \
	{"mul", mul},    \
	{"add", add},    \
	{"sub", sub},    \
	{"mod", mod},     \
	{"pchar", pchar}, \
	{"pstr", pstr},   \
	{"rotl", rotl},   \
	{"rotr", rotr},   \
	{                     \
		NULL, NULL      \
	}                     \
}

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

/**
 * struct help - argument for the current opcode
 * @data_struct: stack mode, stack (default) and queue
 * @argument: the arguments of the string
 *
 * Description: global structure used to pass data around the functions easily
 */
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

/* stack utility functions available in linked_list.c */
stack_t *add_node(stack_t **, const int);
stack_t *queue_node(stack_t **, const int);
void free_stack(stack_t *);
size_t print_stack(const stack_t *);

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

void my_div(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

void opcode(stack_t **, char *, unsigned int);

int is_digit(char *);
int isnumber(char *);

#endif /* MONTY_H */
