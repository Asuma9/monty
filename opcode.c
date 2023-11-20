#include "./monty.h"

/**
 * opcode - runs builtins functions
 * @head: first element of the stack passed by main
 * @str: string to compare
 * @line_num: tracks the line number
 */

void opcode(stack_t **head, char *str, unsigned int line_num)
{
	int index = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "head"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[index].opcode)
	{
		if (strcmp(op[index].opcode, str) == 0)
		{
			op[index].f(head, line_num);
			return; /* if mach found, run the function */
		}
		index++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
	exit(EXIT_FAILURE);
}
