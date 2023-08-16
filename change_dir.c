#include "shell.h"

void change_dir(char **args)
{
    int i = 0;
    char oldpwd[100];
    char *path = args[1];

    if(strcmp(path, "-") == 0)
    {
        //! fix me
        if (chdir(getenv("OLDPWD")) == -1) {
            perror("cd");
        }
    }else if(strcmp(path, "~") == 0)
    {
        if (chdir(getenv("HOME")) == -1) {
            perror("cd");
        }
    }
    else
    {
    
        getcwd(oldpwd, sizeof(oldpwd));
        setenv("OLDPWD", oldpwd, 1);
        if (path == NULL) {
            exit(FAILURE);
        } else {
            if (chdir(path) == -1) {
                perror("cd");
            }
        }
    }

    
    /* free mem */
    while(args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
    
}