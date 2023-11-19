#include "monty.h"

/**
  *rotl - rotates the stack to the top
  *@head: head of the stack
  *@line_num: counts the line under operation
 */
void rotl(stack_t **head, __attribute__((unused)) unsigned int line_num)
{
	stack_t *temp = *head, *top;

	if (*head == NULL || (*head)->next == NULL)
		return;
	top = (*head)->next;
	top->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = top;
}
