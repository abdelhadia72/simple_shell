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
<<<<<<< HEAD
char* _which(char *cmd);
char* _getenv(char *target_env);
void runcmd(char *cmd);
=======
int _which(char *commend);
char* _getenv(const char *target_env);
void runcmd(const char *cmd);
void splitString(char *input, char *delimiter);
>>>>>>> 5410d009a4e59da68e42e672d32aaf7d4a70a653

#endif
