#include "shell.h"

char *_getenv(const char *name)
{
    int i;
    extern char **environ;
    size_t namelen = strlen(name);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, namelen) == 0 && environ[i][namelen] == '=')
        {
            return environ[i] + namelen + 1;
        }
    }

    return NULL;
}
