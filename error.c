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
