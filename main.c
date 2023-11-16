#include "monty.h"

/**
 * main - program entry point
 * @argc: Count of command line arguments
 * @argv: Arguments array
 * Return: 0 always
 */

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2) /*test if appropriate no of arguments is passed*/
		err(1);
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
  *free_nodes - frees nodes in stack for effective memory management
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;/*temporariry store header info in the temporary node*/
		head = head->next;/*shift head pointer to the next node*/
		free(tmp);
	}
}

/**
  *create_node - creates and populates a node with data
  *@data: data to entered into the node
  *Return: Pointer to the created node on success, NULL otherwise
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		err(4);/*Calling malloc failure error*/

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}
