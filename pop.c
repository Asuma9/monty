#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: first element of the stack passed by main in start.c
 * @line_num: gives the line number for error messages
 */

void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	free(*head);
	*head = temp;
	if (!*head)
		return; /* prevent error occurrence if next line might assign a NULL */
	(*head)->prev = NULL;
}
