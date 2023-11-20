#include "monty.h"

/**
 * push - pushes an element into the stack
 * @head: first element of the stack passed by main
 * @line_num: gives the line number of the error message
 */

void push(stack_t **head, unsigned int line_num)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(head, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(head, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
