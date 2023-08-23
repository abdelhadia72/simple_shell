#include "shell.h"
#include <sys/wait.h>

int main(int ac, char **av)
{
	char *buffer = NULL;
	char **args = {NULL};
	size_t size = 0;

	(void)ac;
	(void)av;

	if (isatty(0))
	{
		_puts("$ ");
	}
	while (getline(&buffer, &size, stdin) != EOF)
	{
		buffer[_strlen(buffer) - 1] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}
		if (!space_check(buffer))
		{
			args = spliter(buffer);

			if (strcmp(args[0], "cd") == 0)
				change_dir(args);
			else
			{
				pid_t child_pid = fork();

				if (child_pid == 0)
				{
					execvp(args[0], args);
					perror("execvp");
					exit(2);
				}
				else if (child_pid > 0)
				{
					int status;
					waitpid(child_pid, &status, 0);
					if (WIFEXITED(status))
					{
						int exit_status = WEXITSTATUS(status);
						if (exit_status == 2)
						{
							perror("Command execution failed");
						}
					}
				}
				else
				{
					perror("fork");
				}
			}
		}
		else
		{
			/*printf("%s\n", buffer);*/
		}

		if (isatty(0))
			_puts("$ ");
	}

	free(buffer);
	return 0;
}
