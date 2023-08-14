#include "shell.h"

void runcmd(char **args)
{
    char *path = NULL;
    pid_t pid = fork();
    int i = 0;
    
    // char *envp[] = {
    //     "TERM=xterm",
    //     "PATH=/usr/bin",
    //     "CT=home",
    //     NULL
    // };
    char **envp = environ; 
    // char *envp[] = { "PATH=usr/bin/", NULL };
    int stat;

    if (pid == 0)
    {
        path = which(args[0]);
        if (path)
        {
            execve(path, args, envp);
            printf("free me1\n");
            perror("execve");
            free(path);
            exit(1);
            
        }
        else
        {
            printf("free me2\n");
            perror("execve");
            exit(1);
        }
            printf("free me3\n");
        
    }
    else if (pid > 0)
    {   
            printf("free me4\n");
        
    
        wait(NULL);
        waitpid(pid, &stat, 0);
    }
    else
    {
            printf("free me5\n");
    
        perror("fork");
    
    }
        while(args[i])
        {
            free(args[i]);
            i++;
        }
        free(args);
        printf("free me6\n");
    
}