#include "shell.h"

int space_check(char *buffer)
{
    while(*buffer)
    {
        if (*buffer != ' ' && *buffer != '\n' && *buffer != '\t')
        {
            return(0);
        }
        buffer++;
    }
    return(1);
}