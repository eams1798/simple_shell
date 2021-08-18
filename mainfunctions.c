#include "new_shell.h"

char **tokenizer(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0;
	unsigned int mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(mcount * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	if (*buffer == '\n' || *buffer == ' ')
		return (NULL);
	while ((tokens[i] = _strtok_all(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == mcount)
		{
			tokens = realloc(tokens, mcount);
			if (tokens == NULL)
				return (NULL);
		}
		buffer = NULL;
	}
	return (tokens);
}

func_a argf[] = {
	{"ls", list_files},
	{"exit", file_exit},
	{NULL, NULL}
	 };

void (*match(vars_t *vars))(vars_t *)
{
	func_a *ptr = argf;

	while(ptr->namef != NULL)
	{
		if (strcmp(ptr->namef, vars->arguments[0]) == 0)
		{
			return (ptr->func);
		}
		ptr++;
	}
	return (err_invarg);
}
