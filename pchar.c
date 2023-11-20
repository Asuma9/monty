#include "monty.h"

/**
 * pchar - converts and prints int at the top of the stack as char
 * @head: first element of the stack passed by main
 * @line_num: track the line number
 */

void pchar(stack_t **head, unsigned int line_num)
{
	if (!head || !(*head))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*head)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*head)->n);
}
