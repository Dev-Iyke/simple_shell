#include "shell.h"

void cd_builtins(char **args);
/**
 * cd_builtins - Change the current directory
 * @args: The arguments array
 */
void cd_builtins(char **args)
{
	char *new_folder, *working_folder, *current_folder;

	/* If no arguments, change to the home directory */
	if (args == NULL || args[0] == NULL)
	{
		new_folder = getenv("HOME");
		if (new_folder == NULL)
		{
			fprintf(stderr, "./my_shell: cd: HOME environment variable not set\n");
			return;
		}
	}
	/* If the argument is "-", change to the previous directory */
	else if (strcmp(args[0], "-") == 0)
	{
		new_folder = getenv("OLDPWD");
		if (new_folder == NULL)
		{
			fprintf(stderr, "./my_shell: cd: OLDPWD environment variable not set\n");
			return;
		}
	}
	/* Otherwise, change to the specified directory */
	else
	{
		new_folder = args[0];
	}

	/* Get the current directory */
	current_folder = getcwd(NULL, 0);
	if (current_folder == NULL)
	{
		perror("./my_shell");
		return;
	}

	/* Attempt to change to the new directory */
	if (chdir(new_folder) != 0)
	{
		fprintf(stderr, "./my_shell: cd: %s: No such file or directory\n", args[0]);
	}
	else
	{
		/* On successful directory change, update environment variables */
		working_folder = getcwd(NULL, 0);
		if (working_folder == NULL)
		{
			perror("./my_shell");
			return;
		}

		if (setenv("PWD", working_folder, 1) != 0)
		{
			perror("./my_shell");
		}

		if (setenv("OLDPWD", current_folder, 1) != 0)
		{
			perror("./my_shell");
		}

		/* If the argument is "-", print the current directory */
		if (args[0] && strcmp(args[0], "-") == 0)
		{
			fprintf(stdout, "%s\n", getenv("PWD"));
		}

		/* Free allocated memory */
		free(working_folder);
	}

	free(current_folder);
}
