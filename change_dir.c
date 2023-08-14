#include "shell.h"

void change_dir(char **args)
{
    int i = 0;

    if (args[1] == NULL) {
        exit(FAILURE);
    } else {
        if (chdir(args[1]) == -1) {
            perror("cd");
        }
        while(args[i])
        {
            free(args[i]);
            i++;
        }
        free(args);
    }
}