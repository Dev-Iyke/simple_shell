#ifndef SHELL_H
#define SHELL_H

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

#define MAX_LINE_LENGTH 1024





int read_user_input(char **input, size_t *data);

void display_prompt(void);


void write_to_output(const char *message, size_t length);
ssize_t custom_getline(char **input, size_t *n, FILE *stream);
void tokenize_tokens(char *data_line);
void cd_builtins(char **arguments);
void set_environment_variable(char **arguments);
int env_builtins(char **result);

void unset_environment_variable(char **arguments);


int handle_custom_builtins(char **command_tokens);

void run_executable(char *executable, char **arguments);
void execute_command(char **tokens);

char *find_absolute_path(const char *cmdline);

int execute_env(void);
void custom_unset_environment(char **arguments);
void custom_set_environment(char **arguments);
extern char **environ;

void run_command(char **tokens);

#endif
