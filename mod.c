#include "monty.h"

/**
 * mod - gives the remainder of the division operation
 * @head: first element of the stack
 * @line_num: tracks the current line
 */

void mod(stack_t **head, unsigned int line_num)
{
	int result;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*head)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*head)->next->n) % ((*head)->n);
	pop(head, line_num);/*For top node*/
	(*head)->n = result;
}
