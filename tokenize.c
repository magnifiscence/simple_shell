#include "shell.h"

/**
 * int_token - function associates with othe token functions.
 * @line: string to be tokenized.
 * @sep: delimeter
 * @token_iterator: number of tokens in resulting array
 * Return: dynamically allocated array of strings is returned on success
 */
char **int_token(char *line, const char *sep, int token_iterator)
{
	char **args_arr;

	token_iterator = countToken(line, sep);
	if (token_iterator == -1)
	{
		free(line);
		return (NULL);
	}
	args_arr = split_str(token_iterator, line, sep);
	if (args_arr == NULL)
	{
		free(line);
		return (NULL);
	}
	return (args_arr);
}

/**
 * split_str - function uses delimeter to split string and.
 * returns tokens.
 * @str: string to be tokenized
 * @sep: delimeter
 * @token_len: number of tokens in resulting array
 * Return: dynamically allocated array of strings representing
 * the tokens
 */
char **split_str(int token_len, char *str, const char *sep)
{
	int index;
	char **buff, *tok, *sep_cp;

	sep_cp = _strdub(str);
	buff = malloc(sizeof(char *) * (token_len + 1));
	if (buff == NULL)
	{
		return (NULL);
	}
	tok = strtok(sep_cp, sep);
	for (index = 0; tok != NULL; index++)
	{
		buff[index] = _strdub(tok);
		tok = strtok(NULL, sep);
	}
	buff[index] = NULL;
	free(sep_cp);
	return (buff);
}

/**
 * countToken - function count tokens in input string.
 * @lin: input string
 * @sep: delimeter that seperates tokens
 * Return: number of tokens on success
 * -1 otherwise
 */
int countToken(char *lin, const char *sep)
{
	char *s, *tok;
	int index;

	s = _strdub(lin);
	if (s == NULL)
	{
		return (-1);
	}
	tok = strtok(s, sep);
	for (index = 0; tok != NULL; index++)
	{
		tok = strtok(NULL, sep);
	}
	free(s);
	return (index);
}
