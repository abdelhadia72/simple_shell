#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
	WAX 3RFTI XWHAL WANNA MDABZZ M3AHA BAX N5DMA DYNAMIQUE
*/

char* _getline(size_t buffer_size)
{
	char* buffer;
	size_t buffer_index = 0;
	size_t chars_in_buffer = 0;

	char* line = NULL;
	size_t line_length = 0;

	buffer = (char*)malloc(buffer_size * sizeof(char));

	while (1) {
		if (buffer_index >= chars_in_buffer) {
			chars_in_buffer = read(0, buffer, buffer_size);
			buffer_index = 0;

			if (chars_in_buffer == 0) {
				if (line_length == 0) {
					free(buffer);
					return NULL;
				} else
				{
					break;
				}
			}
		}

		char current_char = buffer[buffer_index++];
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

	free(buffer);
	return line;
}

/* TESTING THE GET LINE FUNCTION */

