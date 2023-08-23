#include "shell.h"

void printenv()
{
    extern char **environ;
    char **env;

    for (env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}