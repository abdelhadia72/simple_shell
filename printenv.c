#include "shell.h"

void printenv()
{
    extern char **environ;
    int envIndex;
    char newlineChar = '\n';

    if (!environ)
        exit(1);

    for (envIndex = 0; environ[envIndex]; envIndex++)
    {
        write(STDOUT_FILENO, environ[envIndex], _strlen(environ[envIndex]));
        write(STDOUT_FILENO, &newlineChar, 1);
    }
}
