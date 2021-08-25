#include "new_shell.h"
/**
 * free_vars - free memory used on buffers
 * @vars: Struct with buffer elements
 * Return: Nothing
 */
void free_vars(vars_t *vars)
{
	int i = 0;

	for (; vars->arguments[i] != NULL; i++)
		if (i != 0)
		{
			i--;
			for (; i >= 0; i--)
			{
				free(vars->arguments[i]);
			}
		}
	free(vars->arguments);
	free(vars->buffer);
	vars->arguments = NULL;
	vars->buffer = NULL;
}

void list_files(vars_t *vars)
{
	(void)vars;
	printf("ls command not implemented, but shows a successful message\n");
}
/**
 * file_exit - Exit program
 * @vars: Struct with buffer elements
 * Return: Nothing
 */
void file_exit(vars_t *vars)
{
	free_vars(vars);
	exit(0);
}
/**
 * err_invarg - print command not found
 * @vars: Struct with buffer elements
 * Return: Nothing
 */
void err_invarg(vars_t *vars)
{
	printf("%s: command not found\n", vars->arguments[0]);
}
