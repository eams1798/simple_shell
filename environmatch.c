#define _POSIX_SOURCE
#include "new_shell.h"
#include <signal.h>
#include <errno.h>

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

	for (i = 0; paths[i] != NULL; i++)
	{
		sz = _strlen(paths[i]);
		paths[i] = realloc(paths[i], (sz + 2) * sizeof(char));
		_strcat(paths[i], "/");
	}
}

/**
 * get_PATHS - get and tokenizes paths
 *
 * Return: Token of Paths
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

/**
 * execcmd - execute a command in a new process
 * @cmdpath: a string with the command and the path
 * @vars: a struct with the arguments of the given command
 * @envp: the environment of the system
 *
 * Return: 1 in the main process, it means the function works
 */
int execcmd(char *cmdpath, vars_t *vars, char **envp)
{
	pid_t child = fork();
	int status;

	if (child == 0)
	{
		if (execve(cmdpath, vars->arguments, envp) == -1)
			exit(errno);
		file_exit(vars);
	}
	else if (child < 0)
		perror("hsh");
	else
		wait(&status);
	return (1);
}

/**
 * match_sys - Execute command on the new shell
 * @vars: Struct with buffer elements
 *
 * Return: 1 on success, -1 on error, or 0 if the command was not found
 */
int match_sys(vars_t *vars)
{
	char **envpath = get_PATHS();
	char *strpath = malloc(1);
	char *cmd = vars->arguments[0];
	int szcmd, szpth, size, i, done;

	szcmd = _strlen(cmd);
	for (i = 0; envpath[i] != NULL; i++)
	{
		if (vars->arguments[0][0] != '/')
		{
			szpth = _strlen(envpath[i]);
			size = szpth + szcmd + 1;
			strpath = realloc(strpath, size * sizeof(char));
			 _strcpy(strpath, envpath[i]);
			 _strcat(strpath, cmd);
		}
		else
		{
			strpath = realloc(strpath, (szcmd + 1) * sizeof(char));
			_strcpy(strpath, cmd);
		}
		if (access(strpath, F_OK) == 0)
		{
			done = execcmd(strpath, vars, environ);
			break;
		}
	}
	free(strpath);
	if (envpath[i] == NULL)
		done = 0;
	i = 0;
	while (envpath[i] != NULL)
		i++;
	i--;
	for (; i >= 0; i--)
		free(envpath[i]);
	free(envpath);
	envpath = NULL;
	cmd = NULL;
	return (done);
}
