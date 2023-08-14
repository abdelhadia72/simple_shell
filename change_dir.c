#include "shell.h"

void change_dir(char **args)
{
    if (args[1] == NULL) {
        exit(FAILURE);
    } else {
        if (chdir(args[1]) == -1) {
            perror("cd");
        }
    }
}