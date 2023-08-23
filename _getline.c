#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int *_getline(char **buffer, size_t *buffer_size, FILE *stream)
{
	size_t buffer_index = 0;
	size_t chars_in_buffer = 0;
	char current_char;

	char *line = NULL;
	size_t line_length = 0;

	*buffer = (char *)malloc(*buffer_size * sizeof(char));

	while (1)
	{
		if (buffer_index >= chars_in_buffer)
		{
			chars_in_buffer = fread(*buffer, sizeof(char), *buffer_size, stream);
			buffer_index = 0;

			if (chars_in_buffer == 0)
			{
				if (line_length == 0)
				{
					free(*buffer);
					return NULL;
				}
				else
				{
					break;
				}
			}
		}

		current_char = (*buffer)[buffer_index++];
		if (current_char == '\n')
		{
			break;
		}

		line = realloc(line, line_length + 1);
		line[line_length++] = current_char;
	}

	if (line != NULL)
	{
		line = realloc(line, line_length + 1);
		line[line_length] = '\0';
	}

	return line;
}
