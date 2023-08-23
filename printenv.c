#include "shell.h"

void printenv()
{
    extern char **environ;

    for (char **env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}