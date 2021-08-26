#define _POSIX_SOURCE
#include "new_shell.h"
#include <signal.h>
#include <errno.h>

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
 * take_command - concatenates the command with its respective path
 * @cmd: only the command
 * @path: the path of the command
 *
 * Return: a command with its path
 */
char *take_command(char *cmd, char *path)
{
	int szcmd = _strlen(cmd), szpth = _strlen(path), newsz;
	char *command;

	if (cmd[0] != '/')
	{
		newsz = (szpth + szcmd + 1) * sizeof(char);
		command = malloc(newsz);
		_strcpy(command, path);
		_strcat(command, cmd);
	}
	else
	{
		newsz = (szcmd + 1) * sizeof(char);
		command = malloc(newsz);
		_strcpy(command, cmd);
	}
	return (command);
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
	char *strpath;
	int i, done;

	for (i = 0; envpath[i] != NULL; i++)
	{
		strpath = take_command(vars->arguments[0], envpath[i]);
		if (access(strpath, F_OK) == 0)
		{
			done = execcmd(strpath, vars, environ);
			break;
		}
		free(strpath);
		strpath = NULL;
	}
	if (strpath != NULL)
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
	return (done);
}
