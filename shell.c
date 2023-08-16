#include "shell.h"

int exit_code;

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
            exit(98);
            break;
        }
        

        // check on spaces
        if(!space_check(buffer))
        {
            args = spliter(buffer);
            
            if (strcmp(args[0], "cd") == 0) {
                change_dir(args);
            }else  if (strcmp(buffer, "echo $?") == 0)
            {
                printf("%d\n",exit_code);
            }else  if (strcmp(buffer, "echo $$") == 0)
            {
                printf("%d\n",getppid());
            }
            else
            {
                runcmd(args);
            }
        }else
        {
            // printf("%s\n", buffer);
        }
        
        if (isatty(0)) {
            _puts("$ ");
        }
    }
}