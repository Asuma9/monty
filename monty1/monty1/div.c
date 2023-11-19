#include "monty.h"

/**
  *my_div - divides the first 2 elements of the stack
  *@head: head of the stack
  *@line_num: count of the line in operation
 */
void my_div(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't div, stack is too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = top->next->n / top->n;
	top->next->n = result;
	*head = top->next;
	free(top);
}
