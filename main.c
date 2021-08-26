#define _GNU_SOURCE
#include "new_shell.h"

void sigintHandler(int sig_num)
{
	signal(SIGINT, sigintHandler);
	(void)sig_num;
	write(STDOUT_FILENO, "\n$ ", 3);
}

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
	signal(SIGINT, sigintHandler);
	while (getline(&(vars.buffer), &buffer_len, stdin) != EOF)
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
	file_exit(&vars);
	return (0);
}
