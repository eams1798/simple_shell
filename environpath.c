#include "new_shell.h"

/**
 * getenv_PATH - get list of PATHs
 *
 * Return: string with PATHs
 */
char *getenv_PATH()
{
	char **var;
	char *envpath;

	for (var = environ; *var != NULL; var++)
	{
		if (_strncmp(*var, "PATH", 4) == 0)
		{
			envpath = *var;
			break;
		}
	}
	envpath += 5;
	return (envpath);
}

/**
 * add_backslash - Add a backslash at the end of each string
 * @paths: String to process
 *
 * Return: Nothing
 */
void add_backslash(char **paths)
{
	int i, sz;
	char *aux;

	for (i = 0; paths[i] != NULL; i++)
	{
		sz = _strlen(paths[i]);
		aux = malloc((sz + 2) * sizeof(char));
		_strcpy(aux, paths[i]);
		_strcat(aux, "/");
		free(paths[i]);
		paths[i] = NULL;
		paths[i] = malloc((sz + 2) * sizeof(char));
		_strcpy(paths[i], aux);
		free(aux);
	}
}

/**
 * get_PATHS - get and tokenizes paths
 *
 * Return: token of Paths
 */
char **get_PATHS()
{
	char **paths;
	char *envpath = malloc((_strlen(getenv_PATH()) + 2) * sizeof(char));
	char *delimiter = ": ";

	_strcpy(envpath, getenv_PATH());
	_strcat(envpath, ":");
	paths = _strtok_all(envpath, delimiter);
	free(envpath);
	add_backslash(paths);
	return (paths);
}
