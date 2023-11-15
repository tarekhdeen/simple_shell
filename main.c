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

	while (1)
	{
		display_prompt();

		if (!read_command(command))
		{
			break;
		}

		if (execute_command(command) == -1)
		{
			break;
		}
	}


	return (0);
}
