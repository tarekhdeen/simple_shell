#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

/**
 * main - Emtry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *program_name = "./shell";
	int status;

	while (1)
	{
		display_prompt();

		if (!read_command(input))
		{
			break;
		}

		if (strcmp(input, "exit\n") == 0)
		{
			exit_shell(0);
		}
		else if (strncmp(input, "exit ", 5) == 0)
		{
			status = atoi(input + 5);
			exit_shell(status);
		}
		else if (strcmp(input, "env\n") == 0)
		{
			print_environment();
		}
		else
		{
			commands_ators(input, program_name);
		}
	}

	return (0);
}
