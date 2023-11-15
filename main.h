#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

void hd_print(const char *format, ...);
void display_prompt(void);
int read_command(char *command);
int execute_command(char *command, char *program_name);
void commands_ators(char *commands, char *program_name);
int tokenize_command(char *command, char *args[]);
void print_environment(void);
void exit_shell(int status);
void change_directory(char *args[]);

#endif /* MAIN_H */
