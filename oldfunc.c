#include "new_shell.h"

/**
 * _strlen - returns the length of a string.
 * @str: a string of characters
 *
 * Return: the length of the string s
 */
int _strlen(char str[])
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}


/**
 * _strcmp - compares two strings
 * @s: a string
 * @t: a string
 *
 * Return: the result of the comparations in both strings
 */
int _strcmp(char *s, char *t)
{
	int dif = 0;
	char *s1 = s, *s2 = t;

	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != '\0' && *s2 != '\0')
		dif = *s1 - *s2;
	s1 = NULL;
	s2 = NULL;
	return (dif);
}

/**
 * _strncmp - compares some bytes of two strings
 * @s: a string
 * @t: a string
 * @n: the number of bytes to be compared
 *
 * Return: the result of the comparations in both strings
 */
int _strncmp(char *s, char *t, int n)
{
	int dif = 0;
	char *s1 = s, *s2 = t;

	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 != '\0' && *s2 != '\0')
		dif = *s1 - *s2;
	s1 = NULL;
	s2 = NULL;
	return (dif);
}

/**
 * _strcat - concatenates two strings
 * @dest: a string
 * @src: a string
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int lenDest = _strlen(dest);
	int lenSrc = _strlen(src);

	for (i = 0; i <= lenSrc; i++)
	{
		dest[lenDest + i] = src[i];
	}
	return (dest);
}

/**
 * _strcpy - copies a string
 * @dest: a copy of the string
 * @src: a string to copy
 *
 * Return: a pointer to the copied string dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr;

	if (dest == NULL)
		return (NULL);
	ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}
