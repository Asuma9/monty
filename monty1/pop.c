#include "monty.h"

/**
  *pop - prints the top of the stack
  *@head: head of the stack
  *@line_num: counts line in operation
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	*head = top->next;
	free(top);
}
