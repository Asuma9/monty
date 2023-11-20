#include "monty.h"

/**
 * rotr - rotates the last node of a stack_t stack
 * @head: first element of the stack passed by main
 * @line_num: gives a line count of the error message
 */

void rotr(stack_t **head, unsigned int line_num)
{
	stack_t *bottom;
	stack_t *prev;

	(void) line_num;
	if (!head || !*head || !(*head)->next)
		return;

	bottom = *head;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *head;
	bottom->prev = NULL;
	prev->next = NULL;
	(*head)->prev = bottom;
	*head = bottom;
}
