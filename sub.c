#include "monty.h"

/**
 * sub -  substracts the first two nodes of the stack
 * @head: first element of the stack passed by main
 * @line_num: gives a line counter of the error message
 *
 * Return: void
 */

void sub(stack_t **head, unsigned int line_num)
{
	int result;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	result = ((*head)->next->n) - ((*head)->n);
	pop(head, line_num);/*For the first node*/
	(*head)->n = result;
}
