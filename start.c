#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

void file_error(char *argv);
void error_usage(void);
int status = 0;

/* global var declaration */

/**
 * main - program entry point
 * @argv: array list of arguments passed to the program
 * @argc: count of arguments passed
 * Return: void
 */

int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *head = NULL;
	unsigned int line_num = 1;

	global.data_struct = 1;  /* struct defined in monty.h*/
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);  /* def in line 68 */

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_num++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_num++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&head, str, line_num);
		line_num++;
	}
	free(buffer);
	free_stack(head);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - prints file error message and exits
 * @argv: array list passed by main()
 *
 * Desc: print error msg if fopen() fails
 */

void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - prints error usage message and exits
 *
 * Desc: if user does not give any file name or more than
 * one argument to your program
 *
 * Return: nothing
 */

void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
