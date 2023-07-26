#include "shell.h"

/**
 * create_path - function creates path by combining two strings one
 * representing the command line and the other the path directory.
 * @dir: represents directory in a path
 * @cmd: file in a directory of the path
 * Return: on success a string representing the full path of a command
 * otherwise NULL.
 */
char *create_path(char *dir, char *cmd)
{
	int x, y, dir_len, cmd_len, len;
	char *built;

	if (dir == NULL || cmd == NULL)
		return (NULL);
	dir_len = _strlen(dir) + 1;
	cmd_len = _strlen(cmd) + 1;
	len = dir_len + cmd_len;

	built = malloc(sizeof(char) * len);
	if (built == NULL)
		return (NULL);

	for (x = 0; x < len; x++)
	{
		for (y = 0; dir[y] != '\0'; y++, x++)
			built[x] = dir[y];
		built[x] = '/';
		x++;
		for (y = 0; cmd[y] != '\0'; y++, x++)
			built[x] = cmd[y];
	}
	built[--x] = '\0';
	return (built);
}

/**
 * search_dir - checks directories for pathh of commands
 * @path_token: pointer to array of strings
 * @cmd: command
 * Return: on success string with command file is returned
 * otherwise NULL
 */
char *search_dir(char **path_token, char *cmd)
{
	int i, s;
	char *buf, *cwd;
	size_t size;
	struct stat stat_buf;

	buf = NULL;
	size = 0;
	cwd = getcwd(buf, size);
	if (cwd == NULL)
		return (NULL);
	if (cmd[0] == '/')
		cmd += 1;
	for (i = 0; path_token[i] != NULL; i++)
	{
		s = chdir(path_token[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(cmd, &stat_buf);
		if (s == 0)
		{
			chdir(cwd);
			free(cwd);
			return (path_token[i]);
		}
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}

/**
 * path_finder - represent interface for functions that will be able
 * to lacate the full path of a program.
 * @cmd: command
 * Return: 0 on success with a string that contains the full path
 * of the program
 */
char *path_finder(char *cmd)
{
	char *constr, *str = "PATH", **p_tokens;
	int index;
	char *dir;

	index = locate_path(str);
	p_tokens = tokenize_path(index, str);
	if (p_tokens == NULL)
	{
		return (NULL);
	}

	dir = search_dir(p_tokens, cmd);
	if (dir == NULL)
	{
		free_db(p_tokens);
		return (NULL);
	}

	constr = create_path(dir, cmd);
	if (constr == NULL)
	{
		free_db(p_tokens);
		return (NULL);
	}

	free_db(p_tokens);
	return (constr);
}

/**
 * locate_path - function finds the index of an environment variable
 * @str: string representing environment variable to be found
 * Return: index of environmental variable on success -1 on failure.
 */

int locate_path(char *str)
{
	int i, j, len;

	len = _strlen(str);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != str[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}

/**
 * tokenize_path - tokenize string
 * @index: path index in environment variable
 * @str: string that is to be seperated and tokenized
 * Return: Null terminated array of pointer to string on success.
 */

char **tokenize_path(int index, char *str)
{
	char *env_var;
	int token_count;
	const char *sep = ":\n";
	char **p_tokens;
	int len;

	len = _strlen(str);
	token_count = 0;

	env_var = environ[index] + (len + 1);
	p_tokens = int_token(env_var, sep, token_count);
	if (p_tokens == NULL)
		return (NULL);
	return (p_tokens);
}
