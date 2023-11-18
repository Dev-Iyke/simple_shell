#include "shell.h"

/**
 * find_absolute_path - Find the absolute path of the command
 * @cmdline: Command line (name of the command)
 *
 * Return: Absolute path if found, NULL otherwise
 */
char *find_absolute_path(const char *cmdline)
{
	char path[1024];
	char *dup_path_buf = strdup(getenv("PATH"));
	char *path_token = strtok(dup_path_buf, ":");

	while (path_token != NULL)
	{
		snprintf(path, sizeof(path), "%s/%s", path_token, cmdline);

		if (access(path, X_OK) == 0)
		{
			free(dup_path_buf);
			return (strdup(path));
		}

		path_token = strtok(NULL, ":");
	}

	free(dup_path_buf);
	return (NULL);
}
