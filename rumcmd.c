#include "shell.h"

/**
 * runcmd - Execute a command in a new process.
 *
 * @args: Array of strings containing the command and its arguments.
 *
 */
void runcmd(char **args)
{
    char *path = NULL;
    pid_t pid = fork();
    int i = 0;
    int stat;

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        if (args[0][0] == '/')
        {
            path = args[0];
        }
        else
        {
            path = which(args[0]);
            if (!path)
            {
                fprintf(stderr, "Command not found: %s\n", args[0]);
                exit(1);
            }
        }

        if (execve(path, args, environ) == -1)
        {
            perror("execve");
            free(path);
            exit(1);
        }
    }
    else
    {
        waitpid(pid, &stat, 0);
    }

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}
