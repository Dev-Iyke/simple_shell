#include "shell.h"


int env_builtins(char **result);

/**
 * env_builtins - Would handle built-in commands related to environment
 * @result: Tokenized command and arguments
 * Return: 1 if a built-in command was handled, 0 otherwise
 */

int env_builtins(char **result)
{
	if (strcmp(result[0], "setenv") == 0)
	{
		set_environment_variable(result + 1);
	}
	else if (strcmp(result[0], "unsetenv") == 0)
	{
		unset_environment_variable(result + 1);
	}
	else if (strcmp(result[0], "env") == 0)
	{
		/* Handle env built-in or modify as needed */
	}
	else if (strcmp(result[0], "cd") == 0)
	{
		cd_builtins(result + 1);
		return (1); /* Indicate that a built-in was handled */
	}
	return (0); /* Not a built-in */
}
