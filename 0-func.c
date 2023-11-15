#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

/**
 * display_prompt - Display prompt
 */
void display_prompt(void)
{
	printf("cisfun$ ");
}

/**
 * read_command - reading command
 * @command: an input string
 *
 * Return: command
 */
int read_command(char *command)
{
	return (fgets(command, MAX_INPUT_LENGTH, stdin) != NULL);
}




/**
 * execute_command - executing command
 * @command: an input string
 *
 * Return: 0
 */
int execute_command(char *command)
{
	int status;
	char *args[MAX_INPUT_LENGTH];
	pid_t pid = fork();

	command[strcspn(command, "\n")] = 0;

	if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Fork failed");
		return (-1);
	}
	else
	{
		waitpid(pid, &status, 0);

		return (0);
	}
}
