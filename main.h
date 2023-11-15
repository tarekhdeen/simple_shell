#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

int _putchar(char c);
void display_prompt(void);
int read_command(char *command);
int execute_command(char *args[], char *program_name);
void commands_ators(char *commands);
int tokenize_command(char *command, char *args[]);
void print_environment(void);
void exit_shell(int status);
void change_directory(char *args[]);

#endif /* MAIN_H */
