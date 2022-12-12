#include "main.h"

/**
 * _read - reads a single line from stdin, removes the newline character,
 * and returns a pointer to the edited string
 * Return: pointer to the edited stdin string
 */
char *_read(void)
{
	ssize_t readsize = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	readsize = getline(&buffer, &n, stdin);
	if (readsize == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}

	if (buffer[readsize - 1] == '\n' || buffer[readsize - 1] == '\t')
	{
		buffer[readsize - 1] = '\0';
	}

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
