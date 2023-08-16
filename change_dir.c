#include "shell.h"

void change_dir(char **args)
{
    int i = 0;
    char oldpwd[100];
    char *path = args[1];
    
    // getcwd(oldpwd, sizeof(oldpwd));
    // setenv("OLDPWD", oldpwd, 1);
    // printf("old path is -> %s\n", getenv("OLDPWD"));
    // printf("before %s\n", oldpwd);
    
    // printf("oldpwd %s\n", getenv("OLDPWD"));
    if(strcmp(path, "-") == 0)
    {
        //! fix me

        
        printf("changed to the preiv dir\n");
        if (chdir(getenv("OLDPWD")) == -1) {
            perror("cd");
        }
    } else
    {
    
        printf("-----------------\n");
        getcwd(oldpwd, sizeof(oldpwd));
        setenv("OLDPWD", oldpwd, 1);
        printf("old path is -> %s\n", getenv("OLDPWD"));
        printf("after %s\n", oldpwd);
    
        if (path == NULL) {
            exit(FAILURE);
        } else {
            if (chdir(path) == -1) {
                perror("cd");
            }
        }
    }

    
    /* free mem */
    while(args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
    
}

// get the current directory
// set it the the old_pwd 
// then change the directory
//! remove the repat of the code 