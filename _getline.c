#include <stdio.h>
#include <stdlib.h>

int _getline(char **lineptr, size_t *n, FILE *stream)
{

	int bytesRead = 0;
	size_t totalBytesRead = 0;
	int ch;
	char *newLineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return -1;
		}
	}

	while ((ch = fgetc(stream)) != EOF)
	{
		if (totalBytesRead >= *n - 1)
		{
			*n *= 2;
			newLineptr = (char *)realloc(*lineptr, *n);
			if (newLineptr == NULL)
			{
				return -1;
			}
			*lineptr = newLineptr;
		}

		(*lineptr)[totalBytesRead++] = (char)ch;
		bytesRead++;

		if (ch == '\n')
		{
			break;
		}
	}

	if (totalBytesRead == 0 && bytesRead == 0)
	{
		return -1;
	}

	(*lineptr)[totalBytesRead] = '\0';

	return totalBytesRead;
}
