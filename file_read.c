#include "monty.h"
#include <stdio.h>


/**
  *open_file - opens a file descriptor
  *@file_op: - opened filename string
 */

void open_file(char *file_op)
{
	int check_file; /*assist to check if function was a sucess*/
	FILE *fd;

	if (file_op == NULL)
		err(2, file_op);
	check_file = access(file_op, R_OK);
	if (check_file == -1)
		err(2, file_op);
	fd = fopen(file_op, "r");
	if (fd == NULL)
		err(2, file_op);

	read_file(fd); /*handles errors*/
	fclose(fd); /*close open file when done*/
}
/**
  *read_file - used to read the contents of a file line by line
  *@fd: pointer to a file descriptor of an open file
 */

void read_file(FILE *fd)
{
	int format = 0;
	int line_num;
	char *line_ptr = NULL;
	size_t n = 0;

	if (fd == NULL)
		err(2, "file_name");

	/*reading line by line in the file*/
	for (line_num = 1; getline(&line_ptr, &n, fd) != -1; line_num++)
		format = interpret_line(line_ptr, line_num, format);

	free(line_ptr);
}
/**
  *interpret_line - tokenizes each line to determine which function to call
  *@line_ptr: pointer to a string to be read from a file
  *@line_num: line number for the opcode read
  *@format: format specifier. If 0, enter Nodes as a stack, if 1
  *enter nodes as a queue
  *Return: 0 if the opcode is stack. 1 if queue
 */

int interpret_line(char *line_ptr, int line_num, int format)
{
	const char *delim;
	char *opcode;
	char *value;

	if (line_ptr == NULL)
		err(4);
	delim = "\n ";
	opcode = strtok(line_ptr, delim);

	/*Handling blank lines*/
	if (opcode == NULL)
		return (format);

	value = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	select_func(opcode, value, line_num, format);
	return (format);

}
/**
  *select_func - selects appropriate function to run the opcode instructions
  *@opcode: The operation code e.g, pull, pall etc
  *@value: the possible value for the operation
  *@line_num: line number for the opject code.
  *@format: Format specifier. 0, enter nodes as a stack, 1 enter nodes
  *as a queue
 */

void select_func(char *opcode, char *value, int line_num, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	/*Ignore lines starting with #*/
	if (opcode[0] == '#')
		return;

	/*Iterates through list to find the right function to select*/
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		/*If the opcode matches, call the associated function*/
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_num, format);
			flag = 0; /*set flag to 0 to indicate a match was found*/
		}
	}

	/*If no match found, call the err function with error code 3*/
	if (flag == 1)
		err(3, line_num, opcode);
}
/**
  *call_fun - calls the required function
  *@f: pointer to selected function to be called
  *@opcode: string representing the opcode
  *@value: string representing a numeric value
  *@line_num: line number for the instructon
  *@format: Format specifier. 0, enter nodes as a stack, 1 enter nodes
  *as a queue
 */

void call_fun(op_func f, char *opcode, char *value, int line_num, int format)
{
	int i;
	int flag;
	stack_t *new_node;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		/*check if the number is -ve and moves the val pointer*/
		if (value != NULL && value[0] == '-')
		{
			value += 1;
			flag = -1; /*set flag to -1 for negative numbers*/
		}

		/*checks if val is not a digit*/
		if (value == NULL)
			err(5, line_num);

		for (i = 0; value[i] != '\0'; i++)
		{
			if (!isdigit(value[i]))
				err(5, line_num);
		}

		/*create a new node with the value and applies the flag*/
		new_node = create_node(atoi(value) * flag);

		/*call appropriate function based on the format*/
		if (format == 0)
			f(&new_node, line_num);
	}
	else
	{
		/*for non-push, call the function with the head of the stack*/
		f(&head, line_num);
	}
}
