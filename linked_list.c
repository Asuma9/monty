#include "monty.h"

/**
 * queue_node - adds a node to a stack_t stack in queue_node
 * @head: first node of stack
 * @n: node data number
 *Return: newly created node, NULL if memory allocation fails.
 */
stack_t *queue_node(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *head;

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;

	if (!*head)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (temp)
	{
		if (!temp->next)
		{
			new_node->next = NULL;
			new_node->prev = temp;
			temp->next = new_node;
			break;
		}
		temp = temp->next;
	}

	return (new_node);
}

/**
 * add_node - adds a node to the start of the stack_t stack
 * @head: first element of stack
 * @n: number for the new node added
 *
 * Return: newly created node, NULL if memory allocation fails.
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (NULL);
	}
	new_node->n = n;

	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}

/**
 * print_stack - prints the contents of the  stack_t stack
 * @head: firts element of the stack
 * Return: number of elements of the list stack
 */
size_t print_stack(const stack_t *head)
{
	size_t index = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		index++;
	}

	return (index);
}

/**
 * free_stack - frees the double dlistint_t linked list
 * @head: first element of the list
 */

void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	if (head)
	{
		next = head->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
