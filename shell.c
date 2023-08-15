#include "shell.h"

int main(int ac, char **av)
{
    char *buffer = NULL;
    char **args = {NULL};
    size_t size = 0;
    
    if (isatty(0)) {
        _puts("$ ");
    }
    while(getline(&buffer, &size, stdin) != EOF)
    {
        buffer[strlen(buffer) - 1] = '\0';
        
        if(strcmp(buffer, "exit") == 0)
        {
            free(buffer);
            perror(buffer);
            break;
        }
        
        
        args = spliter(buffer);
        
        if (strcmp(args[0], "cd") == 0) {
            change_dir(args);
        }
        else
        {
            runcmd(args);
        }
        
    if (isatty(0)) {
        _puts("$ ");
    }
    }
}
