#include "monty.h"

/**
 * err - write to stdout with appropriate error messages determined by
 * their error code
 * @error_code: they are as follows:
 * -> user does not give any file or more than one file to the program
 * -> FIle provided is a corrupted file
 * -> File provided contains invalid instructions
 * -> Program fails to malloc more memory
 * -> parameter passed to the instructions "push" is not an int
 * -> The stack is empty for pint
 * -> stack is empty is empty for po
 * -> stack is too short for operation
 */

void err(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			printf("L%d: unknown instruction %s\n", va_arg(args, int),
					va_arg(args, char *));
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}

	va_end(args);
	exit(EXIT_FAILURE);
}
/**
  *more_errors - handles additional errors
  *@error_code: are as follows
  *->6 when stack is empty for pint
  *->7 when stack is empty for pop
  *->8 when stack is too short for operatio
  *->9 Division by zero
 */
void more_errors(int error_code, ...)
{
	va_list args;
	int line_num;
	char *op;

	va_start(ars, error_code);
	switch (error_code)
	{
		case 6:
			printf("L%d: cant pint, stack empty\n",
					var_arg(args, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n",
					va_arg(ag, int));
			break;
		case 8:
			line_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			printf("L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			printf("L%d: division by zero\n",
					va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
  *string_err - handles string errors
  *@error_code: errros are as follows
  *->10 when number inside node is outside ASCII bounds
  *->11 when stack is empty
 */

void string_err(int error_code, ...)
{
	va_list args;
	int line_num;

	va_start(arg, error_code);
	line_num = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			printf("L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			printf("L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
