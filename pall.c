#include "monty.h"
/**
  *pall - &rints the stack
  *@head: head of the stack
  *@line_num: count of line but not used
 */

void pall(stack_t **head, unsigned int line_num)
{
	stack_t *top;
	(void)line_num;

	top = *head;
	if (top == NULL)
		return;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
