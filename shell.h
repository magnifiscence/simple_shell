#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#define PROMPT "$ "

/**
 * struct builtin - this structure represents build-in commands and
 * its corresponding functions.
 * @num: name of built-in command.
 * @cmd_func: represents pointer to the function that executes
 * the built-in command.
 */
typedef struct builtin
{
	char *num;
	void (*cmd_func)(char *);
} builtin_res;
extern char **environ;

int _strcmp(char *, char *);
int _putchar(char);
int _strlen(char *);

int print_num(int nin);
void _printstr(char *, int);
char *_strdub(char *);

void free_db(char **);
void free_sng(int, ...);
void print_err(char *, int, char *);
void handle_exec_error(char *, int, char *);
char **split_str(int, char *, const char *);
char **int_token(char *, const char *, int);
int countToken(char *, const char *);
void line_format(char *, size_t, int, char **);
void spawn_process(char **, char *, int, char **);
char *creat_path(char *, char *);
char *search_dir(char **, char *);
char **tokenize_path(int, char *);
char *path_finder(char *);
int locate_path(char *);
void cmd_cd(char *);

void cmd_env(char *);
void cmd_exit(char *);
void (*builtin_handler(char *))(char *);
int execute_builtin(char **, char *);

#endif
