#include "shell.h"
/**
 * execute_builtin - function executes a built_in command if it exist
 * @args: argument arrays passed to the shell.
 * @line: string that contains input from user.
 * Return: 0 for success -1 for error or command not a built_in.
 */
int execute_builtin(char **args, char *line)
{
	void (*func)(char *);

	func = builtin_handler(args[0]);
	if (func == NULL)
	{
		return (-1);
	}
	if (_strcmp("exit", args[0]) == 0)
	{
		free_db(args);
	}
	func(line);
	return (0);
}
