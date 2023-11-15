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
 * tokenize_command - Tokenize the command and dynamically allocate memory
 *                    for the args array
 * @command: An input string
 * @args:    The array to store the tokens
 *
 * Return: Number of tokens
 */
int tokenize_command(char *command, char *args[])
{
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i] = malloc(strlen(token) + 1);
		if (args[i] == NULL)
		{
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}
		strcpy(args[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (i);
}


/**
 * execute_command - executing command
 * @args: an input string
 * @program_name: program name
 *
 * Return: 0
 */
int execute_command(char *args[], char *program_name)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		if (args[0][0] == '/')
		{
			execv(args[0], args);
		}
		else
		{
			execvp(args[0], args);
		}
		perror(program_name);
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
		return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
	}
}
