#include "shell.h"

/**
 * builtin_handler - predicts the function needed for execution
 * @s: name of the function.
 * Return: void
 */
void (*builtin_handler(char *s))(char *s)
{
	int res;

	builtin_res beta[] = {
		{"env", cmd_env},
		{"exit", cmd_exit},
		{"cd", cmd_cd},
		{NULL, NULL}
	};

	for (res = 0; beta[res].num != NULL; res++)
	{
		if (_strcmp(s, beta[res].num) == 0)
		{
			return (beta[res].cmd_func);
		}
	}
	return (NULL);
}

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
