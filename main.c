#define _GNU_SOURCE
#include "new_shell.h"

/**
 * main - Process inputs of new shell
 *
 * Return: Nothing
 */
int main(void)
{
	vars_t vars = {NULL, NULL};
	size_t buffer_len = 0;
	char *delimiter =  " \n";
	char *buffercur;

	write(STDOUT_FILENO, "$ ", 2);
	while (getline(&(vars.buffer), &buffer_len, stdin) != -1)
	{
		buffercur = cure_buffer(vars.buffer);
		if (buffercur != NULL)
			vars.arguments = _strtok_all(buffercur, delimiter);
		free(buffercur);
		if (vars.arguments != NULL)
		{
			if (_strcmp(vars.arguments[0], "exit") == 0)
				file_exit(&vars);
			if (match_sys(&vars) == 0)
				err_invarg(&vars);
			free_vars(&vars);
		}
		fflush(stdin);
		write(STDOUT_FILENO, "$ ", 2);
	}
	return (0);
}
