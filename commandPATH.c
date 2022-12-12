#include "main.h"

/**
 * _memset - fill first n bytes of the memory area
 * pointed to by *s with char b
 * @s: pointer to the memory area to be filled
 * @b: the character to fill the memory with
 * @n: number of bytes to fill
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x = 0;

	while (x < n)
	{
		s[x] = b;
		x++;
	}
	return (s);
}
/**
 * _concatPATHloc - concatenate path location with / and command
 * @tmp: mem location
 * @tokenArray: array of tokenized arguments passed to the program
 * @tok: tokenized string from the PATH environment variable
 * Return: mem location of concatenated string
 */
char *_concatPATHloc(char *tmp, char **tokenArray, char *tok)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(tok) + _strlen(tokenArray[0]) + 2;
	_strcat(tmp, tok);
	_strcat(tmp, "/"); /* add / to end of PATH */
	_strcat(tmp, tokenArray[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
/**
 * _countPATHdirectories - count the directories that
 * branch out of the PATH directory
 * @str: PATH directory (string containing all directories
 * of PATH, separated by the : delimiter)
 * Return: number of directories in PATH directory
 */
int _countPATHdirectories(char *str)
{
	int i;
	int searchflag = 1;
	int directorycount = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ':' && searchflag == 1)
		{
			directorycount += 1;
			searchflag = 0;
		}
		if (str[i + 1] == ':')
		{
			searchflag = 1;
		}
	}
	return (directorycount);
}
/**
 * _commandPATH - takes the PATH environment variable and splits it into tokens
 * , concatenates each token with the first argument of the command line,
 * and checks if the resulting string is a valid path.
 * If it is valid _commandPATH returns the full path of the command.
 * @tokenArray: array of tokenized arguments passed to the program
 * @PATH: PATH directory name "PATH"
 * @copy: copy of the PATH environment variable
 * Return: pointer to command PATH string
 */
char *_commandPATH(char **tokenArray, char *PATH, char *copy)
{
	int PATHcount = 0, fullpathflag = 0, length = 0, toklen = 0;
	char *tok, *commandPATH = NULL, *concatstr = NULL;
	struct stat statbuff;
	static char tmp[256];

	copy = NULL;
	copy = _strdup(PATH);
	PATHcount = _countPATHdirectories(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _concatPATHloc(tmp, tokenArray, tok);
		if (stat(concatstr, &statbuff) == 0)
		{
			commandPATH = concatstr;
			fullpathflag = 1;
			break;
		}
		if (length < PATHcount - 2)
		{
			toklen = _strlen(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(tokenArray[0], &statbuff) == 0)
				{
					commandPATH = tokenArray[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		length++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		commandPATH = tokenArray[0];
	free(copy);
	return (commandPATH);
}
