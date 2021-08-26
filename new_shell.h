#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct variables - A struct which stores the text of one line and converts
 * in tokens to use as arguments of a program
 * @buffer: the text of the given line
 * @arguments: the line converted in many arguments to use in a program
 *
 * Description: stores content of a line converts it in arguments for a
 * program
 */
typedef struct variables
{
	char *buffer;
	char **arguments;
} vars_t;

extern char **environ;
int _strlen(char str[]);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
char *getenv_PATH();
void add_backslash(char **paths);
char **get_PATHS();
char **_strtok_all(char *buffer, char *delimiter);
char *cure_buffer(char *buffer);
int match_sys(vars_t *vars);
void file_exit(vars_t *vars);
void err_invarg(vars_t *vars);
void free_vars(vars_t *vars);

#endif
