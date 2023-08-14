#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* macros */
#define SUCCESS 0
#define FAILURE -1

/* functions */
char **spliter(char *buffer);

#endif

