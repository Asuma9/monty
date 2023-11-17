#include "monty.h"

/**
  *sub - subtracts the first 2 elements
  *@head: head of the stack
  *@line_num: count of the line in operation
 */
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *top;
	int index, result;

	top = *head;
	for (index = 0; top != NULL; index++)
		top = top->next;
	if (index < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	result = top->next->n - top->n;
	top->next->n = result;
	*head = top->next;
	free(top);
}
