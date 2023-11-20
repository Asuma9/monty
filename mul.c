#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mul - multiplies the next top value by the top value
 * @head: first element of the stack passed by main
 * @line_num: line counter
*/

void mul(stack_t **head, unsigned int line_num)
{
	int result;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*head)->next->n) * ((*head)->n);
	pop(head, line_num);/*to remove the top node*/
	(*head)->n = result;
}
