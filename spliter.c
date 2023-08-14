#include "shell.h"

char **spliter(char *buffer)
{
    char *copy_buffer = NULL;
    char *token = NULL;
    char *sp = " \n\t";
    size_t n_char = 0;


    copy_buffer = strdup(buffer);
    token = strtok(copy_buffer, sp);
    while (token != NULL)
    {
        n_char++;
        token = strtok(NULL, sp);
    }
    n_char++;

    int i = 0;
    char **argv = malloc(sizeof(char *) * n_char);

    copy_buffer = strdup(buffer);
    token = strtok(copy_buffer, sp);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = malloc(strlen(token) + 1);
        strcpy(argv[i], token);

        token = strtok(NULL, sp);
    }
    argv[i] = NULL;

    free(copy_buffer);
    
    // int o = 0;
    // while(argv[o])
    // {
    //     printf("-> %s\n", argv[o]);
    //     o++;
    // }

    return (argv);
}