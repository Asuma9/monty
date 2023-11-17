#include "monty.h"

/**
  *free_stack - frees stack of doubly linked list
  *@head: head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *top;

	top = head;
	while (head)
	{
		top = head->next;
		free(head);
		head = top;
	}
}
