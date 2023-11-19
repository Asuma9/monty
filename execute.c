#include "monty.h"

/**
  *execute - executes the opcode
  *@head: head of linked list stack
  *@line_num: count of line we are operating in
  *@file: pointer to monty file
  *@content: line content of monty file
  *Return: nothing
 */

int execute(char *content, stack_t **head, unsigned int line_num, FILE *file)
{
	instruction_t opst[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},	{"pop", pop},
		{"swap", swap},	{"add", add}, {"nop", nop}, {"div", my_div}, {"sub", sub},
		{"mul", mul}, {"pchar", pchar},
		{"pstr", pstr},	{"rotl", rotl},	{"rotr", rotr},	{"queue", queue},
		{"stack", stack},
		{NULL, NULL},
	};

	unsigned int index = 0;
	char *op;

	op = strtok(content, " \n\t");

	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[index].opcode && op)
	{
		if (strcmp(op, opst[index].opcode) == 0)
		{
			opst[index].f(head, line_num);
			return (0);
		}
		index++;
	}
	if (op && opst[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
