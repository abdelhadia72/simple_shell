#include "shell.h"

char* _getenv(const char *target_env) {
    unsigned int i = 0;
    extern char **environ;
    char *token = NULL;

    while (environ[i]) {
        char *cp_env = strdup(environ[i]);

        token = strtok(cp_env, "=");
        if (token && strcmp(token, target_env) == 0) {
            token = strtok(NULL, "=");
            free(cp_env);
            return (token);
        }

        free(cp_env);
        i++;
    }

    return (NULL);
}

