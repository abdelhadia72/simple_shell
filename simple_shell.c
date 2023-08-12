#include "shell.h"

int main()
{
	char input[MAX_INPUT_LENGTH];
	int status;

	while (1)
	{
		// display the promet
		printf("#cisfun$ ");
		fflush(stdout);

		// read user input
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			// handle Ctrl+D
			break;
		}
		// execute command using execve
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("error");
			exit(1);
		}
		else if (child_pid == 0)
		{
			if (strlen(input) > 0)
			{
				if (execlp(input, input, NULL) == -1)
				{
					perror("error");
					exit(1);
				}
			}
			exit(0);
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	return 0;
}
