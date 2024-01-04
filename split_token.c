#include "shell.h"
void tokenize_tokens(char *data_line);

/**
 * tokenize_tokens - Function to split data_line into tokens
 * @data_line: Input string to be split
 */
void tokenize_tokens(char *data_line)
{
	char *result, *strim_line, *end;
	char *delim = " \t\n";
	char **tokens = NULL;
	int token_count = 0, u;

	strim_line = strdup(data_line);
	if (strim_line == NULL)
	{
		perror("String duplication failed");
		exit(EXIT_FAILURE);
	}

	while (*strim_line == ' ' || *strim_line == '\t')
	{
		strim_line++;
	}

	end = strim_line + strlen(strim_line) - 1;

	while (end > strim_line && (*end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}

	tokens = malloc(sizeof(char *) * MAX_LINE_LENGTH);
	if (!tokens)
	{
		perror("Memory allocation for tokens failed");
		free(strim_line);
		exit(EXIT_FAILURE);
	}

	result = strtok(strim_line, delim);

	while (result != NULL)
	{
		tokens[token_count] = strdup(result);

		if (tokens[token_count] == NULL)
		{
			perror("String duplication failed");
			free(strim_line);
			free(tokens);
			exit(EXIT_FAILURE);
		}

		token_count++;
		result = strtok(NULL, delim);
	}
	tokens[token_count] = NULL;

	if (token_count > 0)
	{
		run_command(tokens);
	}

	free(strim_line);

	for (u = 0; u < token_count; u++)
	{
		free(tokens[u]);
	}
	free(tokens);
}
