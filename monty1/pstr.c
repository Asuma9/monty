#include "monty.h"
/**
  *pstr - prints string in stack starting from the top of the stack
  *@head: head of stack
  *@line_num: count of stack line we are at
 */

void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *top;
	(void)line_num;

	top = *head;
	while (top)
	{
		if (top->n > 127 || top->n <= 0)
		{
			break;
		}
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}
