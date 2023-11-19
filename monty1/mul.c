#include "monty.h"

/**
  *mul - multiplies the first top 2 elements of a stack
  *@head: head of the stack
  *@line_num: count of line in operation
 */
void mul(stack_t **head, unsigned int line_num)
{
	stack_t *top;
	int index = 0, result;

	top = *head;
	while (top)
	{
		top = top->next;
		index++;
	}
	if (index < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	result = top->next->n * top->n;
	top->next->n = result;
	*head = top->next;
	free(top);
}
