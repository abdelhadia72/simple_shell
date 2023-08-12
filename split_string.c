#include "shell.h"

void splitString(char *input, char *delimiter) {
	char *buf = strdup(input);
	if (buf == NULL) {
		perror("eror");
		return;
	}

	int tokenCount = 0;
	char *p = strtok(buf, delimiter);

	while (p != NULL) {
		tokenCount++;
		p = strtok(NULL, delimiter);
	}

	char **array = (char **)malloc(tokenCount * sizeof(char *));
	if (array == NULL) {
		perror("eror");
		free(buf);
		return;
	}

	char *inputCopy = strdup(input);
	p = strtok(inputCopy, delimiter);
	for (int i = 0; i < tokenCount; ++i) {
		array[i] = strdup(p);
		p = strtok(NULL, delimiter);
	}

	free(inputCopy);

	for (int i = 0; i < tokenCount; ++i) {
		printf("%s\n", array[i]);
		free(array[i]);
	}

	free(array);
	free(buf);
}
