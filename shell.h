#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* exit */
extern int exit_status;

/* environment */
extern char **environ;

/* macros */
#define SUCCESS 0
#define FAILURE -1

/* functions */
char **spliter(char *buffer);
char *which(char *cmd);
void runcmd(char **args);
void change_dir(char **args);
int space_check(char *buffer);
char *_strtok(char *str, const char *delim);
int _getline(char **buffer, size_t *buffer_size, FILE *stream);
char *_getenv(const char *name);
void printenv();

/* help function */
int _putchar(char c);
void _puts(char *str);
char *rm_spaces(char *str);

/* Str function */
int _strlen(const char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *nptr);
char *_strcat(char *dest, char *src);
/* char *_strdup(const char *str); */

#endif
