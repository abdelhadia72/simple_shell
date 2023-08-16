#include "shell.h"

/**
 * main - Entry point for the custom shell program.
 *
 * @ac: Number of command-line arguments.
 * @av: Array of command-line argument strings.
 *
 * Return: Always returns 0.
 */

int main(int ac, char **av)
{
	char *buffer = NULL;
	char **args = {NULL};
	size_t size = 0;
	
	if (isatty(0))
	{
		_puts("$ ");
	}
	while(getline(&buffer, &size, stdin) != EOF)
	{
		buffer[_strlen(buffer) - 1] = '\0';
		
		if(_strcmp(buffer, "exit") == 0)
		{
			/*
			free(buffer);
			perror(buffer);
			exit(98);
			break;
			*/

			// try to handle arguments for the built-in exit task 8
			free(buffer);
			exit_status = 0;

			if (args[1] != NULL)
			{
				exit_status = atoi(args[1]);
			}

			exit(exit_status);
			break;
		}
		
		// check on spaces
		if(!space_check(buffer))
		{
			args = spliter(buffer);
			
			if (_strcmp(args[0], "cd") == 0)
			{
				change_dir(args);
			}
			else if(_strcmp(buffer, "echo $?") == 0)
			{
				printf("exit %d", exit_status);
			}
			else if (_strcmp(buffer, "echo $$") == 0)
			{
				printf("%d\n",getppid());
			}
			else
			{
				runcmd(args);
			}
		}else
		{
			// printf("%s\n", buffer);
		}
		
		if (isatty(0))
		{
			_puts("$ ");
		}
	}
}


// if (WIFEXITEO(wstatus))
// int statusCode = WEXITSTATUS(wstatus);
