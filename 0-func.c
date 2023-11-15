#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_INPUT_LENGTH 100

/**
 * display_prompt - Display prompt
 */
void display_prompt(void)
{
	hd_print("cisfun$ ");
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
 * tokenize_command - tokenize command
 * @command: a string
 * @args: an array
 *
 * Return: i
 */
int tokenize_command(char *command, char *args[])
{
	char *token;
	int i = 0;

<<<<<<< HEAD
=======
	token = strtok(command, " \n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	return (i);
}

/**
 * print_environment - print env
 */
void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		hd_print("%s\n", *env);
		env++;
	}
}

>>>>>>> 12487fb6ad67f3471018e825445fb68957ab471a
/**
 * execute_command - executing command
 * @command: an input string
 *
 * Return: 0
 */
int execute_command(char *command, char *program_name)
{
	char *args[MAX_INPUT_LENGTH];
	int status;
	pid_t pid = fork();

	tokenize_command(command, args);

	if (pid == 0)
	{
		if (strcmp(args[0], "cd") == 0)
		{
			change_directory(args);
			exit(EXIT_SUCCESS);
		}
		else
		{
			execvp(args[0], args);
			perror(program_name);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Fork failed");
		return (-1);
	}
	else
	{
		waitpid(pid, &status, 0);
		{
			return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
		}
	}
}
