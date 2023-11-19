#include "monty.h"

/**
  *pint - prints the top of a stack
  *@head: head of the stack
  *@line_num: count of the line in operation
 */
void pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
