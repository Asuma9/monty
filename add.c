#include "monty.h"

/**
 * add -  sum the top 2 two nodes of the stack
 * @head: stack given by main
 * @line_num: keeps track of current line
 */

void add(stack_t **head, unsigned int line_num)
{
	int result;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	result = ((*head)->next->n) + ((*head)->n);
	pop(head, line_num); /*For the first node*/
	(*head)->n = result;
}
