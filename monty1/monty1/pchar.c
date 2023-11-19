#include "monty.h"

/**
  *pchar - prints the character st the top of the stack
  *followed by a new line
  **@head: head os the stack
  *@line_num: count of the line we are operating on
*/

void pchar(stack_t **head,  unsigned int line_num)
{
	stack_t *top;

	top = *head;
	if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of ranger\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
