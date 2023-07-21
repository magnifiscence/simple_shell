#include "shell.h"

/**
 * handle_exec_error - function handles exit and execution errors.
 * @args: represent arguments.
 * @len: number of commands entered.
 * @cmd: failed commands
 */
void handle_exec_error(char *args, int len, char *cmd)
{
	print_err(args, len, cmd);
	_printstr(": ", 1);
	perror("");
	exit(0);
}

/**
 * print_err - function prints a message error when command is not found.
 * @args: arguments
 * @len: represents number of commands executed in the shell
 * @cmd: command that was not found
 */
void print_err(char *args, int len, char *cmd)
{
	_printstr(args, 1);
	_printstr(": ", 1);
	print_num(len);
	_printstr(": ", 1);
	_printstr(cmd, 1);
}
