#include "monty.h"
#include <stdio.h>

/**
 * file_treat - reads the instructions in a monty file and executes them
 * @stack: stack to be treated in the monty code
 * @file_path: monty file path
 * Return: nothing
*/
void file_treat(stack_t **stack, char *file_path)
{
	FILE *file = fopen(file_path, "r");
	char *lineptr = NULL;
	size_t n = 0;
	int r = 0;
	func function;

	if (file == NULL)
	{
		printf("Error: Can't open file %s", file_path);
		exit(EXIT_FAILURE);
	}

	while ((r = getline(&lineptr, &n, file)) != -1)
	{
		function = check_opcode(lineptr);
	}
	if (function != NULL)
		function(stack, 1);
}

/**
 * check_opcode - check the opcode to know what function to use
 * @line: line containing the opcode
 * Return: a pointer to the function to be executed
*/
func check_opcode(char *line)
{
	int i = 0;
	instruction_t instrctions[] = {
		{"push", push_},
		{"pall", pall_},
		{NULL, NULL}
	};
	while (instrctions[i].opcode != NULL)
	{
		if (strcmp(instrctions[i].opcode, line) == 0)
			return (instrctions[i].f);
		i++;
	}
	return (NULL);
}

