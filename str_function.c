#include "shell.h"

/**
 *  _strlen -  calculates the length of a string.
 * @str: pointer to a string.
 * Return: i.
 */

int _strlen(const char *str)
{
	const char *ptr = str;

	while (*ptr)
	{
		ptr++;
	}

	return ptr - str;
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

/**
 * _strcat - concatenates two strings.
 * @dest: destination string
 * @src: source string
 * Return: pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return dest;
}