#include "new_shell.h"

int main()
{
	vars_t vars = {NULL, NULL};
	size_t buffer_len = 0;
	char *delimiter =  " \n";
	char *buffercur;	

	printf("$ ");
	while (getline(&(vars.buffer), &buffer_len, stdin) != -1)
	{
		buffercur = cure_buffer(vars.buffer);
		vars.arguments = tokenizer(buffercur, delimiter);
		if (vars.arguments != NULL)
		{
			(match(&vars))(&vars);
			free_vars(&vars);
		}
		printf("$ ");
	}
	return (0);
}
