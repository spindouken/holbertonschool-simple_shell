#include "main.h"

/**
 * _putchar - writes a character to the standard output
 * @c: character to print
 * Return: the value of write
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printstring - takes a string and prints it to the standard output
 * @str: string to be printed
 * Return: Always Success
 */
void _printstring(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}
/**
 * _printenv - print the environment
 * Return: 0 on completion
 */
int _printenv(void)
{
	int i, j;

	if (!environ || !(*environ))
		return (-1);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			write(STDOUT_FILENO, &environ[i][j], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * builtin_checker - contains the built in functions
 * How it works: checks if the command is built into the shell,
 * if it is a builtin command the associated program will be executed
 * @tokenArray: array of tokenized arguments passed to the program from stdin
 * @CLIbuffer: buffer that contains the command line input (CLI)
 * @exitstatus: exit status of the last command executed
 * Return: value of exit status
 */
int builtin_checker(char **tokenArray, char *CLIbuffer, int exitstatus)
{
	int i;

	/**
	 * Check if the command from stdin is "env", if it is
	 * print the environment variables, then
	 * free the tokenArray, free the buffer, and return 1
	 */
	if (_strcmp(tokenArray[0], "env") == 0)
	{
		_printenv();
		for (i = 0; tokenArray[i]; i++)
			free(tokenArray[i]);
		free(tokenArray);
		free(CLIbuffer);
		return (1);
	}

	/**
	 * check if the command from stdin is "exit", if it is
	 * free all the memory that was allocated for the command,
	 * then exit the shell
	 */
	else if (_strcmp(tokenArray[0], "exit") == 0)
	{
		for (i = 0; tokenArray[i]; i++)
			free(tokenArray[i]);
		free(tokenArray);
		free(CLIbuffer);
		exit(exitstatus);
	}
	else
		return (0);
}
