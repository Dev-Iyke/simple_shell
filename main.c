#include "shell.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: Argument count (unused)
 * @argv: Argument values (unused)
 *
 * Return: Always returns EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	ssize_t input_length;
	char *user_input = NULL;
	size_t buffer_size = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		/* Read user input */
		input_length = read_user_input(&user_input, &buffer_size);

		/* Break the loop if an error occurred during input */
		if (input_length == -1)
		{
			break;
		}

		/* Skip lines starting with '#' or '##' */
		if (user_input[0] == '#' || (user_input[0] == ' ' && user_input[1] == '#'))
		{
			continue;
		}

		/* Tokenize the input */
		tokenize_tokens(user_input);


	}

	/* Free allocated memory for user input */
	free(user_input);

	/* Exit with success status */
	return (EXIT_SUCCESS);
}
