#include "monty.h"

/**
 * rotl - rotates the first element of the stack
 * @head: first element of the stack passed by main
 * @line_num: gives a line count of the error message
 */
void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *left;
	stack_t *right;

	(void) line_num;
	if (!head || !*head || !(*head)->next)
		return;

	left = right = *head;

	while (right->next) /* moves the right pointer to the last node */
		right = right->next;
	right->next = left; /* a circle infinite linked list loop */
	left->prev = right;
	*head = left->next; /* cuts the link between the 0 and 1 element */
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}
