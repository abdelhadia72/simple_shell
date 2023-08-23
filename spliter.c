#include "shell.h"

char **spliter(char *buffer)
{
    char *copy_buffer = NULL;
    char *token = NULL;
    char *sp = " \n\t";
    size_t n_char = 0;
    char **argv = NULL;
    int i = 0;

    copy_buffer = strdup(buffer);
    token = strtok(copy_buffer, sp);
    while (token != NULL)
    {
        n_char++;
        token = strtok(NULL, sp);
    }
    n_char++;

    argv = (char **)malloc(sizeof(char *) * n_char);

    /* /! free before redup */
    free(copy_buffer);
    copy_buffer = strdup(buffer);
    token = strtok(copy_buffer, sp);
    for (i = 0; token != NULL; i++)
    {
        argv[i] = malloc(_strlen(token) + 1);
        _strcpy(argv[i], token);

        token = strtok(NULL, sp);
    }
    argv[i] = NULL;

    free(copy_buffer);

    return (argv);
}
