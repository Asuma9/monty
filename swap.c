#include "monty.h"

/**
 * swap -  swaps data between the top two nodes
 * @head: first element of the stack passed by main
 * @line_num: gives the error message line number
 *
 * Return: void
 */

void swap(stack_t **head, unsigned int line_num)
{
	stack_t *temp = NULL;
	int temp_n = 0;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	temp_n = temp->n;
	temp->n = temp_n;

	temp->n = temp->next->n;
	temp->next->n = temp_n;

}
