#include "shell.h"

/**
 * free_db - function frees memory allocated for a double pointer
 * and its elements.
 * @db_ptr: double pointer to be freed
 */
void free_db(char **db_ptr)
{
	int j;

	for (j = 0; db_ptr[j] != NULL; j++)
	{
		free(db_ptr[j]);
	}
	free(db_ptr);
}
/**
 * print_num - function prints an unsigned number
 * @nin: represents an unsigned int
 * Return:int
 */
int print_number(int nin)
{
	int quo, l;
	unsigned int lat;

	quo = 1;
	l = 0;
	lat = nin;
	while (lat / quo > 9)
	{
		quo *= 10;
	}
	while (quo != 0)
	{
		l += _putchar('0' + lat / quo);
		lat %= quo;
		quo /= 10;
	}
	return (l);
}

/**
 * free_sng - function frees a given number of pointers to strings
 * @num: number of pointers to be freed.
 */
void free_sng(int num, ...)
{
	int count;
	char *ptr;
	va_list args_list;

	va_start(args_list, num);
	for (count = 0; count < num; count++)
	{
		ptr = va_arg(args_list, char*);

		if (ptr == NULL)
		{
			ptr = "(nil)";
		}
		free(ptr);
	}
	va_end(args_list);
}
