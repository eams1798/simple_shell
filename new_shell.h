#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct variables
{
	char *buffer;
	char **arguments;
} vars_t;

typedef struct argfunc
{
	char *namef;
	void (*func)(vars_t *);
} func_a;

char **tokenizer(char *buffer, char *delimiter);
void (*match(vars_t *vars))(vars_t *);
void file_exit(vars_t *vars);
void list_files(vars_t *vars);
void err_invarg(vars_t *vars);

#endif
