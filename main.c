#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

/**
 * main - Emtry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char command[MAX_INPUT_LENGTH];
	char *args[MAX_INPUT_LENGTH];
	char *program_name = "./shell";
	int num_tokens, exit_status, i;

	while (1)
	{
		display_prompt();

		if (!read_command(command))
		{
			break;
		}

		num_tokens = tokenize_command(command, args);
		exit_status = execute_command(args, program_name);

		for (i = 0; i < num_tokens; i++)
		{
			free(args[i]);
		}
		if (exit_status == -1)
		{
			fprintf(stderr, "Command execution failed\n");
		}
	}


	return (0);
}
