#include "shell.h"

char *_strdup(const char *str)
{
    size_t len;
    char *new_str;

    if (str == NULL)
    {
        return NULL;
    }

    len = strlen(str);
    new_str = (char *)malloc(len + 1);
    if (new_str != NULL)
    {
        strcpy(new_str, str);
    }

    return new_str;
}