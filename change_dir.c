#include "shell.h"

void change_dir(char **args)
{
    int i = 0;
    char oldpwd[100];
    char *path = args[1];

    if (path == NULL || strcmp(path, "~") == 0)
    {
        /* Get the home directory path */
        const char *home_path;
        if ((home_path = getenv("HOME")) == NULL)
        {
            struct passwd *pw = getpwuid(getuid());
            if (pw)
            {
                home_path = pw->pw_dir;
            }
        }

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
    else if (strcmp(path, "-") == 0)
    {
        if (chdir(getenv("OLDPWD")) == -1)
        {
            perror("cd");
        }
    }
    else
    {
        getcwd(oldpwd, sizeof(oldpwd));
        setenv("OLDPWD", oldpwd, 1);
        if (chdir(path) == -1)
        {
            perror("cd");
        }
    }

    /* Free memory */
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}
