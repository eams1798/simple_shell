#include "new_shell.h"

/**
 * only_one_space - remove extra blank spaces from buffer and puts the result
 * in other string
 * @dest: src puts the string with no extra blank spaces here
 * @src: the string to be cleaned of extra blank spaces
 *
 * Return: nothing
 */
void only_one_space(char *dest, char *src)
{
	int i, switcher = 0, size = _strlen(src);

	for (i = 0; i <= size; i++)
	{
		while (switcher == 0)
		{
			if (*src != ' ')
			{
				dest[i] = *src;
				if (*src == '\n')
					i++;
				src++;
				break;
			}
			if ((*src == ' ')
					&& (*(src + 1) != ' ' && *(src + 1) != '\n'))
			{
				dest[i] = ' ';
				dest[i + 1] = *(src + 1);
				i++;
				src += 2;
				break;
			}
			src++;
		}
		if (*src == '\0')
			switcher = 1;
		if (switcher == 1)
			dest[i] = '\0';
	}
}

/**
 * rm_first_space - checks if the first character of the given string is a
 * blank spaces and deletes if it is
 * @buffer: a buffer to be checked
 *
 * Return: a new buffer with the correct blank spaces
 */
char *rm_first_space(char *buffer)
{
	int i;
	char *nofs;

	nofs = malloc(_strlen(buffer) * sizeof(char));
	if (nofs == NULL)
	{
		free(nofs);
		return (NULL);
	}
	for (i = 1; i <= _strlen(buffer); i++)
	{
		nofs[i - 1] = buffer[i];
	}
	free(buffer);
	return (nofs);
}

/**
 * cure_buffer - Clean buffer of extra blank spaces
 * @buffer: Buffer to process
 *
 * Return: buffer cured
 */
char *cure_buffer(char *buffer)
{
	int i, size = _strlen(buffer);
	char *j = buffer;
	char *cure = NULL, *aux = NULL;
	char *new = malloc((size + 1) * sizeof(char));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	only_one_space(new, j);
	j = NULL;
	if (new[0] == ' ' || new[0] == '\n')
		aux = rm_first_space(new);
	else
		aux = new;
	if (_strlen(aux) == 0)
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
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
	new = NULL;
	aux = NULL;
	return (cure);
}

/**
 * tokalloc - allocate memory space to the new array of tokens
 * @buffer: a string to be used to create the array of tokens
 * @delim: the delimiters to be used to separate the new tokens
 * @ctok: the number of tokens to be created
 *
 * Return: 0 if the function works succesfully, or -1 on error
 */
char **tokalloc(char *buffer, char *delim, int ctok)
{
	int i, k = 0;
	char **tokens;

	tokens = malloc((ctok + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}
	for (i = 0; i <= ctok; i++)
	{
		if (*buffer == '\0')
		{
			tokens[i] = NULL;
			break;
		}
		while (*buffer != delim[0] && *buffer != delim[1])
		{
			k++;
			buffer++;
		}
		tokens[i] = malloc((k + 1) * sizeof(char));
		if (tokens[i] == NULL)
		{
			for (; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		buffer++;
		k = 0;
	}
	return (tokens);
}

/**
 * _strtok_all - Tokenize buffers with given parameters
 * @buffer: buffer to process
 * @delimiter: string that will separate tokens
 *
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
	tokens = tokalloc(ptr, delimiter, ctok);
	if (tokens == NULL)
		return (NULL);
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
