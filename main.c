#include "new_shell.h"

int main()
{
	vars_t vars = {NULL, NULL};
	size_t buffer_len = 0;
	char *delimiter =  " \n";

	printf("$ ");
	while (getline(&(vars.buffer), &buffer_len, stdin) != -1)
	{
		vars.arguments = tokenizer(vars.buffer, delimiter);
		if (vars.arguments != NULL)
		{
			(match(&vars))(&vars);
			free_vars(&vars);
		}
		printf("$ ");
	}
	return (0);
}
