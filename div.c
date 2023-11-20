#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * my_div - divides the first 2 elements of the stack
 * @head: stack given by main
 * @line_num: counts line in operation
 */

void my_div(stack_t **head, unsigned int line_num)
{
	int result;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (((*head)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		;
		return;
	}

	result = ((*head)->next->n) / ((*head)->n);
	pop(head, line_num);/*For top node*/
	(*head)->n = result;
}
