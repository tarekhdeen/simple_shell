#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * exit_shell - exit shell
 * @status: status
 */
void exit_shell(int status)
{
	exit(status);
}

/**
 * change_directory - change directory
 * @args: args
 */
void change_directory(char *args[])
{
	char *new_dir = args[1];
	char cwd[1024];

	if (new_dir == NULL)
	{
		new_dir = getenv("HOME");
	}
	else if (strcmp(new_dir, "-") == 0)
	{
		new_dir = getenv("OLDPWD");
	}

	if (chdir(new_dir) != 0)
	{
		perror("cd");
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		setenv("PWD", cwd, 1);
		setenv("OLDPWD", getenv("PWD"), 1);
	}
}

/**
 * commands_ators - commands separators and operators
 * @commands: commands
 * @program_name: program name
 */
void commands_ators(char *commands, char *program_name)
{
	char *command;
	char *saveptr;

	command = strtok_r(commands, ";", &saveptr);
	while (command != NULL)
	{
		if (command[0] != '#')
		{
			if (strlen(command) > 1)
			{
				execute_command(command, program_name);
			}
		}
		command = strtok_r(NULL, ";", &saveptr);
	}
}
