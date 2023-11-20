#include "monty.h"

/**
 * pall - prints the stack elements
 * @head: first element of stack given by main in start.c
 * @line_num: tracks the line number
 */

void pall(stack_t **head, unsigned int line_num __attribute__((unused)))
{
	print_stack(*head);
}
