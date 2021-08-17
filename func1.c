#include "new_shell.h"

void list_files(vars_t *vars)
{
	(void)vars;
	printf("ls command not implemented, but shows a successful message\n");
}

void file_exit(vars_t *vars)
{
	int i = 0;

	for (; vars->arguments[i] != NULL; i++);
	if (i != 0)
	{
		i--;
		for (; i >= 0; i--)
		{
			free(vars->arguments[i]);
		}
	}
	free(vars->arguments);
	vars->buffer = NULL;
	exit(0);
}

void err_invarg(vars_t *vars)
{
	printf("%s: command not found\n", vars->arguments[0]);
}
