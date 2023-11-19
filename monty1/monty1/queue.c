#include "monty.h"

/**
  *queue - prints top of the queue
  *@head: head of stack
  *@line_num: count line in operation
 */
void f_queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	bus.lifi = 1;
}

/**
  *addqueue - adds a node to the tail of the stack
  *@n: new value to be added
  *@head: the head of the stack
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *top;

	top = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");

	new_node->n = n;
	new_node->next = NULL;
	if (top)
	{
		while (top->next)
			top = top->next;
	}
	if (!top)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		top->next = new_node;
		new_node->prev = top;
	}
}
