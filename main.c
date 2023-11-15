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
	char command[MAX_INPUT_LENGTH], *args[MAX_INPUT_LENGTH];
	int status;

	while (1)
	{
		display_prompt();
		if (!read_command(command))
		{
			break;
		}
		if (strcmp(command, "exit\n") == 0)
		{
			exit_shell(0);
		}
		else if (strncmp(command, "exit ", 5) == 0)
		{
			status = atoi(command + 5);
			exit_shell(status);
		}
		else if (strcmp(command, "env\n") == 0)
		{
			print_environment();
		}
		else
		{
			tokenize_command(command, args);
			if (strncmp(command, "cd", 2) == 0)
			{
				change_directory(args);
			}
			else
			{
				if (execute_command(command) == -1)
				{
					break;
				}
			}
		}
	}
	return (0);
}
