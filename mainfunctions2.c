#define _POSIX_SOURCE
#include "new_shell.h"
#include <signal.h>
#include <errno.h>
/**
 * getenv_PATH - get list of PATHs
 * Return: string with PATHs
 */
char *getenv_PATH()
{
	char** var;
	char* envpath;
/*	char ph[4];
*/
	for (var = environ; *var != NULL; var++)
	{
/*		ph[0] = (*var)[0];
		ph[1] = (*var)[1];
		ph[2] = (*var)[2];
		ph[3] = (*var)[3];
*/
		if (strncmp(*var, "PATH", 4) == 0)
		{
			envpath = *var;
			break;
		}
	}
	envpath += 5;
	return (envpath);
}
/**
 * add_backslash - Add slash at the end of string
 * @paths: String to process
 * Return: Nothing
 */
void add_backslash(char **paths)
{
	int i, sz;

	for (i = 0; paths[i] != NULL; i++)
	{
		sz = _strlen(paths[i]);
		paths[i] = realloc(paths[i], (sz + 2) * sizeof(char));
		strcat(paths[i], "/");
	}
}
/**
 * get_PATHS - get and tokenizes paths
 * Return: Token of Paths
 */
char **get_PATHS()
{
	char **paths;
	char *envpath = malloc((_strlen(getenv_PATH()) + 2) * sizeof(char));
	char *delimiter = ": ";

	strcpy(envpath, getenv_PATH());
	strcat(envpath, ":");
	paths = _strtok_all(envpath, delimiter);
	free(envpath);
	add_backslash(paths);
	return (paths);
}
/**
 * match_sys - Execute command on the new shell
 * @vars: Struct with buffer elements
 * Return: 1: SUCCESS
		2: FAILURE	
 */
int match_sys(vars_t *vars)
{
	pid_t child;
	char **envpath = get_PATHS();
	char *strpath = malloc(1);
	char *cmd = vars->arguments[0];
	int szcmd, szpth, size, i, done, status;

	szcmd = _strlen(cmd);
	for (i = 0; envpath[i] != NULL; i++)
	{
		szpth = _strlen(envpath[i]);
		size = szpth + szcmd + 1;
		strpath = realloc(strpath, size * sizeof(char));
		strcpy(strpath, envpath[i]);
		strcat(strpath, cmd);
		if (access(strpath, F_OK) == 0)
		{
			child = fork();
			if (child == 0)
			{
				execve(strpath, vars->arguments, environ);
				exit(errno);
				break;
			}
			else if (child < 0)
			{	
				perror("hsh");
				break;
			}
			else
			{
				wait(&status);
				break;
			}
		}	
	}
	free(strpath);
	if (envpath[i] == NULL)
	{
		done = 0;
	}
	else
	{
		done = 1;
	}
	free(envpath);
	cmd = NULL;
	return (done);
}
