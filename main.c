#include "main.h"

/**
 * main - function that runs the framework of the shell
 * Return: 0 on success
 */
int main(void)
{
	char *PATH = NULL;
	ssize_t writecount = 0;
	char **tokenArray;
	char *CLIbuffer = NULL;
	int exitstatus = 0;
	char *copy = NULL;
	char *commandPATHbuffer = NULL;

	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1) /* 1 - keyboard, 0 - terminal */
		{
			writecount = write(STDOUT_FILENO, "$ ", 2);
			if (writecount == -1) /* write returns -1 on error */
				exit(0); /* exit with return value 0 */
		}

		tokenArray = NULL;
		CLIbuffer = _read();
		if (*CLIbuffer != '\0')
		{
			tokenArray = tokenizer(CLIbuffer);
			if (tokenArray == NULL)
			{
				free(CLIbuffer);
				continue;
			}
			commandPATHbuffer = _commandPATH(tokenArray, PATH, copy);
			if (builtin_checker(tokenArray, CLIbuffer, exitstatus) == 1)
				continue;
			exitstatus = forkandReplace(tokenArray, CLIbuffer, commandPATHbuffer);
			/* get exit status of child process */
		}
		else
			free(CLIbuffer);
	}
	return (0);
}
