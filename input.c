#include "shell.h"

/**
 * read_user_input - Would read and parse user input.
 * This function takes a pointer to the input line buffer and the size of the
 * input buffer as parameters. It is responsible for reading user input and
 * parsing it as needed.
 * @input: Pointer to the input line buffer.
 * @data: Size of the input buffer.
 *
 * Return: Number of characters read or -1 on error.
 */

int read_user_input(char **input, size_t *data)
{
	char *prompt = "G$ ";  /* The custom prompt to be displayed */
	int command_length;
	int direct_input = isatty(STDIN_FILENO);

	if (direct_input)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
	}

	command_length = getline(input, data, stdin);  /* Read input line */

	if (command_length == -1)  /* Handle Ctrl+D (EOF) */
	{
		if (direct_input)
			write(STDOUT_FILENO, "\n", 1);
		return (-1);
	}

	if (direct_input && command_length > 0 &&
			(*input)[command_length - 1] == '\n')
	{
		(*input)[command_length - 1] = '\0';
		command_length--;
	}

	return (command_length);  /* Return the number of characters read */
}
