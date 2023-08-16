#include "shell.h"

    extern int exit_code;
char* which(char *cmd)
{
    char *path = NULL;
    char *token = NULL;
    char *cp_cmd = NULL;
    char *sp = ":";
    char *holder = NULL;

    if (!cmd)
        return NULL;

    path = getenv("PATH");
    if (!path)
    {
        return NULL;
    }

    cp_cmd = strdup(cmd);
    token = strtok(path, sp);

    while (token)
    {
        holder = (char *)malloc(strlen(token) + strlen(cmd) + 2);
        strcpy(holder, token);
        strcat(holder, "/");
        strcat(holder, cmd);
        if (access(holder, X_OK) == 0)
        {
        
            free(cp_cmd);
            return (holder);
        }

        free(holder);
        token = strtok(NULL, sp);
    }
    
    free(cp_cmd);
    exit_code = 1;
    perror("which");
    return (NULL);
}

//! you have to make your own getenv ??!