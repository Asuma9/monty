#include "monty.h"

/**
  *swap - swaps the top two elements of the stack
  *@head: head of the stack
  *@line_num: counts line in operation
 */
void swap(stack_t **head, unsigned int line_num)
{
	stack_t *top;
	int index = 0, temp;

	top = *head;
	while (top)
	{
		top = top->next;
		index++;
	}
	if (index < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
