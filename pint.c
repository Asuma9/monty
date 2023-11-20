#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @head: first element of the stack passed by main in start.c
 * @line_num: tracks the line number
 */

void pint(stack_t **head, unsigned int line_num)
{
	if (!head || !(*head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*head)->n);
}
