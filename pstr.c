#include "monty.h"

/**
 * pstr - prints all contents of a stack_t stack as a string
 * @head: first element of the stack passed by main
 * @line_num: gives the line number of error messages
 */

void pstr(stack_t **head, unsigned int line_num __attribute__((unused)))
{
	stack_t *top = *head;

	while (top)
	{
		if (top->n <= 0 || top->n > 127)
			break;
		putchar((char) top->n);
		top = top->next;
	}
	putchar('\n');
}
