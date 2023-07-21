#include "shell.h"

/**
 * cmd_env - function prints environment variables in the current shell.
 * @s: user input
 */
void cmd_env(__attribute__((unused))char *s)
{
int x, y;

for (x = 0; environ[x] != NULL; x++)
{
	for (y = 0; environ[x][y] != '\0'; y++)
	{
		write(STDOUT_FILENO, &environ[x][y], 1);
	}
	write(STDOUT_FILENO, "\n", 1);
}
}

/**
 * cmd_exit - command exits the shell
 * @line: user input
 */
void cmd_exit(char *line)
{
	free(line);
	_printstr("", 1);
	exit(2);
}
/**
 * cmd_cd - command changes current working directory
 * @line: input string
 */
void cmd_cd(char *line)
{
	int index, token_iterator;
	char **args_array;
	const char *delim = "\n\t ";

	token_iterator = 0;
	args_array = int_token(line, delim, token_iterator);
	if (args_array[0] == NULL)
	{
		free_sng(2, args_array, line);
		return;
	}
	if (args_array[1] == NULL)
	{
		index = locate_path("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(args_array[1], "-") == 0)
		_printstr(args_array[1], 0);
	else
		chdir(args_array[1]);
	free_db(args_array);
}
