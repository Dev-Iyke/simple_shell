#include "shell.h"

/**
 * set_environment_variable - Set or update an environment variable.
 * @arguments: An array of strings containing the variable name and value.
 * Return: None.
 */
void set_environment_variable(char **arguments)
{
	/* Check if arguments are valid */
	if (arguments == NULL || arguments[0] == NULL || arguments[1] == NULL)
		return;

	/* Set or update the environment variable */
	if (setenv(arguments[0], arguments[1], 1) == -1)
	{
		/* Handle error if setenv fails */
		return;
	}
}

/**
 * unset_environment_variable - Unset or remove an environment variable.
 * @arguments: An array of strings containing the variable name.
 * Return: None.
 */
void unset_environment_variable(char **arguments)
{
	/* Check if arguments are valid */
	if (arguments == NULL || arguments[0] == NULL)
		return;

	/* Unset or remove the environment variable */
	if (unsetenv(arguments[0]) == -1)
	{
		/* Handle error if unsetenv fails */
		return;
	}
}


/**
 * list_environment - Lists the environment variables.
 * @args: The args array.
 * Return: None.
 */
void list_environment(char **args)
{
	char **environment = environ;
	(void)args;

	for (; *environment; environment++)
	{
		write(STDOUT_FILENO, *environment, strlen(*environment));
		write(STDOUT_FILENO, "\n", 1);
	}
}

