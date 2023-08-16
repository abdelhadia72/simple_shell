#include "shell.h"

void runcmd(char **args)
{
    char *path = NULL;
    pid_t pid = fork();
    int i = 0;
    
    // set the env
    char **envp = environ; 
    int stat;

    if (pid == 0)
    {
        if(args[0][0] == '/')
        {
            path = args[0];
        } else
        {
            path = which(args[0]);
        }
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
        while(args[i])
        {
            free(args[i]);
            i++;
        }
        free(args);
    
}
