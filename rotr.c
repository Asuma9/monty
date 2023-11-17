#include "monty.h"

/**
  *rotr - used to rotate the stack to the bottom
  *@head: head of the stack
  *@line_num: count of stack line we are at
 */

void rotr(stack_t **head, __attribute__((unused)) unsigned int line_num)
{
	stack_t *stack_copy;

	stack_copy = *head;
	if (head == NULL || (*head)->next == NULL)
		return;
	while (stack_copy->next)
		stack_copy = stack_copy->next;
	stack_copy->next = *head;
	stack_copy->prev->next = NULL;
	stack_copy->prev = NULL;
	(*head)->prev = stack_copy;
	(*head) = stack_copy;

}
