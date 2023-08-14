#include "shell.h"

int main(int ac, char **av)
{
    char *buffer = NULL;
    size_t size = 0;
    
    printf("$ ");
    while(getline(&buffer, &size, stdin) != EOF)
    {
        buffer[strlen(buffer) - 1] = '\0';
        
        if(strcmp(buffer, "exit") == 0)
        {
            free(buffer);
            exit(1);
            break;
        }
        
        //! we didn't make it yet...
        //! runcmd(buffer)
        
        printf("buffer: %s\n", buffer);
        printf("$ ");
    }
}