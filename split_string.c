#include "shell.h"

void splitString(char *input, char *delimiter)
{
    char *buf = strdup(input);
    int tokenCount = 0;
    char *p;
    char **array;
    char *inputCopy;
    int i;

    if (buf == NULL)
    {
        perror("error");
        return;
    }

    p = strtok(buf, delimiter);

    while (p != NULL)
    {
        tokenCount++;
        p = strtok(NULL, delimiter);
    }

    array = (char **)malloc(tokenCount * sizeof(char *));

    if (array == NULL)
    {
        perror("error");
        free(buf);
        return;
    }

    inputCopy = strdup(input);

    p = strtok(inputCopy, delimiter);
    for (i = 0; i < tokenCount; ++i)
    {
        array[i] = strdup(p);
        p = strtok(NULL, delimiter);
    }

    free(inputCopy);

    for (i = 0; i < tokenCount; ++i)
    {
        printf("%s\n", array[i]);
        free(array[i]);
    }

    free(array);
    free(buf);
}
