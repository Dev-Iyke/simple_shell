#include "shell.h"

void run_command(char **tokens);

/**
 * run_command - Function to execute a command
 * @tokens: Array of command tokens
 */
void run_command(char **tokens)
{
	pid_t pid;
	int status;
	char *cmdline;
	char *envp[] = {"TERM=xterm", NULL};  /* Updated envp declaration*/

	pid = fork();
	if (pid == -1)
	{
		perror("Execution of command failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		cmdline = tokens[0];

		if (strchr(cmdline, '/'))
		{
			if (execve(cmdline, tokens, envp) == -1)
			{
				perror("Execution of command failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{

			cmdline = find_absolute_path(cmdline);

			if (cmdline == NULL)
			{
				fprintf(stderr, "Command not found: %s\n", tokens[0]);
				exit(EXIT_FAILURE);
			}


			if (execve(cmdline, tokens, envp) == -1)
			{
				perror("Execution of command failed");
				free(cmdline);/* Free the allocated memory for the absolute path*/
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

