#include "shell.h"

void change_dir(char **args)
{
    char oldpwd[265];
    int i;

    if (!args[1] || strcmp(args[1], "~") == 0)
    {
        const char *home_path = getenv("HOME");

        if (home_path)
        {
            if (chdir(home_path) == -1)
            {
                perror("cd");
            }
        }
        else
        {
            fprintf(stderr, "cd: could not determine home directory\n");
        }
    }
    else if (strcmp(args[1], "-") == 0)
    {
        const char *old_path = getenv("OLDPWD");

        if (old_path && chdir(old_path) == -1)
        {
            perror("cd");
        }
    }
    else
    {
        if (getcwd(oldpwd, sizeof(oldpwd)) == NULL)
        {
            perror("getcwd");
        }
        else
        {
            setenv("OLDPWD", oldpwd, 1);
        }

        if (chdir(args[1]) == -1)
        {
            perror("cd");
        }
    }

    for (i = 0; args[i]; ++i)
    {
        free(args[i]);
    }
    free(args);
}
