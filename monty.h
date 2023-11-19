#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdarg.h>


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

/*
  * struct instruction_s - opcode instructions and its function
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
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;

/*Global variable*/

extern bus_t bus;

/*File handling functions*/
int main(int argc, char *argv[]);
int execute(char *, stack_t **, unsigned int, FILE *);
void free_stack(stack_t *);
char *_realloc(char *, unsigned int, unsigned int);
ssize_t getstdin(char **, int);
char *clean_line(char *);

/*stack/node handling operations*/
void addnode(stack_t **, int);
void addqueue(stack_t **, int);
void queue(stack_t **, unsigned int);
void stack(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/*string handling functions*/
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, __attribute__((unused)) unsigned int);

/*Math handling functions*/
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void my_div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

#endif /*MONTY_H*/
