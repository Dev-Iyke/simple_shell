#include "shell.h"

int main(void)
{
	char *command;

	while (1)
	{
	display_prompt();
	command = read_input();
	execute_command(command);
	free(command);
	}

	return 0;
}
