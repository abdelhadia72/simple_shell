#include "shell.h"

/**
 *  _strlen -  calculates the length of a string.
 * @str: pointer to a string.
 * Return: i.
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
  * _strcpy - copys str to another
  * @dest: destination string
  * @src: the str that we gonna copy
  *
  * Return: the pointer to dst
  */


char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';

	return (dest);
}

/**
 * _strncmp - compares first n bytes of s1 and s2
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
