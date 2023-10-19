#include "monty.h"

/**
 * main - main program for the monty language interpreter
 * @ac: arguments count
 * @av: arguments array
 * Return: 0 on succes EXIT_FAILURE if it fails or an error happens
*/
int main(int ac, char **av)
{
	stack_t *stack;

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_treat(&stack, av[1]);
	return (0);
}
