#include "shell.h"

void runcmd(char **args)
{
    char *path = NULL;
    pid_t pid = fork();
    
    char *envp[] = {
        "TERM=xterm",
        "PATH=/usr/bin",
        NULL
    };
    // char *envp[] = { "PATH=usr/bin/", NULL };
    int stat;

    if (pid == 0)
    {
        path = which(args[0]);
        if (path)
        {
            execve(path, args, envp);
            perror("execve");
            free(path);
            exit(1);
        }
        else
        {
            perror("execve");
            exit(1);
        }
    }
    else if (pid > 0)
    {   
        wait(NULL);
        waitpid(pid, &stat, 0);
    }
    else
    {
        perror("fork");
    }
}