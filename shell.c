#include "shell.h"

int main(int ac, char **av)
{
	char *buffer = NULL;
  size_t size = 0;
  int i = 0;
	int status;


  printf("$ ");
	while (getline(&buffer, &size, stdin) != -1)
	{

    buffer[strlen(buffer) - 1] = '\0';
    
    if(strcmp(buffer, "exit") == 0)
    {
      perror("exit");
      break;
      exit(1);
    }
    
    runcmd(buffer);
    printf("$ ");

  }
    free(buffer);
    return (0);
}
