#include "shell.h"

void runcmd(char *cmd)
{
    char *path = NULL;
    pid_t pid = fork();
    char *argv[] = { NULL };
    char **envp = { NULL };
    int stat;

    if (pid == 0)
    {
        path = _which(cmd);

        if (path)
        {
            argv[0] = path;
            execve(path, argv, envp);
            perror("execve");
            free(path);
            exit(1);
        }
        else
        {
            perror(cmd);
            exit(1);
        }
    }
    else if (pid > 0)
    {
        waitpid(pid, &stat, 0);
    }
    else
    {
        perror("fork");
    }
}
