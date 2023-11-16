#include "monty.h"

/**
  *pop_top - add node to the top of stack
  *@top: pointer to pointer to the first node of stack
  *@line_num: count of line number of the opcode
 */

void pop_top(stack_t **top, unsigned int line_num)
{
	stack_t *temp;

	if (top == NULL || *top == NULL)
		more_errors(7, line_num);

	temp = *top;
	*top = temp->next;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(temp);
}

/**
  *print_top - prints top most node of the stack
  *@top: pointer to pointer to top of the stack
  *@line_num: line count of the opcode
 */

void print_top(stack_t **top, unsigned int line_num)
{
	if (top == NULL || *top == NULL)
		more_errors(6, line_num);
	printf("%d\n", (stack)->n);
}
/**
  *add_to_stack - pushes an element to the stack
  *@node: pointer to added node
  *@line_num: line count of the opcode
 */
void add_to_stack(stack_t **node, __attribute__((unused))unsigned int line_num)
{
	stack_t temp;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	head = *node;
	head->next = temp;
	temp->prev = head;
}
/**
  *print_stack - prints all the values on the stack, starting from
  *the top of the stack
  *@stack: pointer to pointer to top of the stack
  *@line_num: line count of the opcode
 */

void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
  *add_to_queue - adds a new node to the queue
  *@node: pointer to the new node to be added
  *@line_num: line count of the opcode
 */
void add_to_queue(stack_t **node, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
