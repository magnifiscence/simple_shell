#include "shell.h"
/**
 * main - entry point of program
 * @argc: represents argument count.
 * @argv: argument vector
 * Return: always 0
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *line;
	size_t size;
	int cmdCount;

	cmdCount = 0;
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		cmdCount++;
		line = NULL;
		size = 0;
		line_format(line, size, cmdCount, argv);
	}
	return (0);
}
