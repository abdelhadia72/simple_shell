#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* exit */
// #define EXIT_CODE 0
/* environment */
extern char **environ;

/* macros */
#define SUCCESS 0
#define FAILURE -1


/* functions */
char **spliter(char *buffer);
char* which(char *cmd);
void runcmd(char **args);
void change_dir(char **args);
int space_check(char *buffer);
char *_strtok(char *str, const char *delim);
char* _getline(size_t buffer_size);


/* help function */
int _putchar(char c);
void _puts(char *str);

#endif
