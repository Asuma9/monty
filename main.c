#include "monty.h"
#include <stdio.h>

bus_t bus = {NULL, NULL, NULL, 0};

/**
  *program entry point for monty interpreter
  *@argc: count of command line arguments
  *@argv: array of arguments
  *Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *content;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *head = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		count++;
		if (read_line > 0)
			execute(content, &head, count, file);
		free(content);
	}
	free_stack(head);
	fclose(file);
	return (0);
}
