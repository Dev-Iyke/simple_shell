#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1024

/* Function Declarations */
void display_prompt(void);
char *read_input(void);
void execute_command(char *command);

#endif
