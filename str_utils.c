#include "shell.h"

/**
 * _putchar - function writes character to stdout.
 * @c: character to be written to stdout.
 * Return: number of characters on succes
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printstr - function prints a string character by character
 * @s: string that is to be printed.
 * @n: interger were new line character is printed if equal to 0.
 */
void _printstr(char *s, int n)
{
	int count;

	if (s == NULL)
	{
		s = "(null)";
	}
	for (count = 0; s[count] != '\0'; count++)
	{
		write(STDOUT_FILENO, &s[count], 1);
	}
	if (n == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * _strlen - function returns length of a string
 * @s: string length to be measured
 * Return: len on success
 */
int _strlen(char *s)
{
	int len;

	if (s == NULL)
	{
		return (0);
	}
	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strcmp - function compares two strings
 * @x: first string
 * @y: second string
 * Return: 0 if strings correspond and -1 otherwise.
 */
int _strcmp(char *x, char *y)
{
	int j;

	if (_strlen(x) != _strlen(y))
	{
		return (-1);
	}

	for (j = 0; x[j] != '\0'; j++)
	{
		if (x[j] != y[j])
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * _strdub - function dublicates a string
 * @start: initial string
 * Return: copy of string
 */
char *_strdub(char *start)
{
	int index, length;
	char *end;

	length = _strlen(start);
	end = malloc(sizeof(char) * (length + 1));
	for (index = 0; start[index] != '\0'; index++)
	{
		end[index] = start[index];
	}
	end[index] = '\0';
	return (end);
}
