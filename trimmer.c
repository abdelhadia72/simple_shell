#include "shell.h"
#include <ctype.h>

char *rm_spaces(char *str)
{
    size_t i;
    size_t len;
    size_t start;
    size_t end;

    if (str == NULL)
        return NULL;

    len = strlen(str);
    start = 0;
    end = len - 1;

    while (isspace((unsigned char)str[start]))
    {
        start++;
    }

    if (start == len)
    {
        str[0] = '\0';
        return str;
    }

    while (end > start && isspace((unsigned char)str[end]))
    {
        end--;
    }

    for (i = start; i <= end; i++)
    {
        str[i - start] = str[i];
    }

    str[end - start + 1] = '\0';

    return str;
}
