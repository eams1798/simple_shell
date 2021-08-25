#include "new_shell.h"
/**
 * _strlen - Calculate length of string
 * @str: String to process
 * Return: Length of given string
 */
int _strlen(char str[])
{
	int i;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}
/**
 * cure_buffer - Clean buffer of extra blank spaces
 * @buffer: Buffer to process
 * Return: buffer cured
 */
char *cure_buffer(char *buffer)
{
	int i, size = _strlen(buffer);
	char *j = buffer;
	int switcher = 0;
	char *cure = NULL, *nofs = NULL, *aux = NULL;
	char *new = malloc((size + 1) * sizeof(char));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	for (i = 0; i <= size; i++)
	{
		while (switcher == 0)
		{
			if (*j != ' ')
			{
				new[i] = *j;
				if (*j == '\n')
					i++;
				j++;
				break;
			}
			if ((*j == ' ')
					&& (*(j + 1) != ' ' && *(j + 1) != '\n'))
			{
				new[i] = ' ';
				new[i + 1] = *(j + 1);
				i++;
				j += 2;
				break;
			}
			j++;
		}
		if (*j == '\0')
			switcher = 1;
		if (switcher == 1)
			new[i] = '\0';
	}
	j = NULL;
	if (new[0] == ' ' || new[0] == '\n')
	{
		nofs = malloc(_strlen(new) * sizeof(char));
		if (nofs == NULL)
		{
			free(nofs);
			return (NULL);
		}
		for (i = 1; i <= _strlen(new); i++)
		{
			nofs[i - 1] = new[i];
		}
		free(new);
		if (*nofs == '\n' || *nofs == '\0')
		{
			free(nofs);
			return (NULL);
		}
		aux = nofs;
	}
	else
		aux = new;
	cure = malloc((1 + _strlen(aux)) * sizeof(char));
	if (cure == NULL)
	{
		free(aux);
		free(cure);
		return (NULL);
	}
	for (i = 0; i < _strlen(aux); i++)
		cure[i] = aux[i];
	cure[i] = '\0';
	free(aux);
	return(cure);
}
/**
 * _strok_all - Tokenize buffers with given parameter
 * @buffer: buffer to process
 * @delimeter: string that will separate tokens
 * Return: Array of tokens
 */
char **_strtok_all(char *buffer, char *delimiter)
{
	int i, j, ctok = 0, k = 0;
	char *ptr = buffer, *ptr2 = buffer;
	int size = _strlen(buffer);
	char **tokens = NULL;

	if (buffer == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (buffer[i] == delimiter[j])
				ctok++;
		}
	}
	tokens = malloc((ctok + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}
	for (i = 0; i <= ctok; i++)
	{
		if (*ptr == '\0')
		{
			tokens[i] = NULL;
			break;
		}
		while (*ptr != delimiter[0] && *ptr != delimiter[1])
		{
			k++;
			ptr++;
		}
		tokens[i] = malloc((k + 1) * sizeof(char));
		if (tokens[i] == NULL)
		{
			for (; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		ptr++;
		k = 0;
	}
	ptr = NULL;
	for (i = 0; i <= ctok; i++)
	{
		if (*ptr2 == '\0')
			break;
		while (*ptr2 != delimiter[0] && *ptr2 != delimiter[1])
		{
			tokens[i][k] = *ptr2;
			ptr2++;
			k++;
		}
		tokens[i][k] = '\0';
		ptr2++;
		k = 0;
	}
	ptr2 = NULL;
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
