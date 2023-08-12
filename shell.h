#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* macors */

#define MAX_INPUT_LENGTH 1024
#define SUCCESS 0
#define FAILURE 1

/* helper functions */
int _which(char *commend);
char* _getenv(const char *target_env);

#endif
