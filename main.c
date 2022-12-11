#include "main.h"

/**
 * _memset - fill first n bytes of the memory area
 * , pointed to by *s, with char b
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
 * _concatPATHloc -
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
 * of PATH, separated by : delimiter)
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
/**
 * _strdup - duplicates a string and returns a pointer
 * to a newly allocated space in memory with the copied string
 * @str: pointer to string to duplicate
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	int i;
	char *dest;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		{ ; }

	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * _strcount - counts the number of words in a string
 * (this will be the user input into command line interpreter)
 * @str: pointer to string to count
 * Return: number of words in string
 */
int _strcount(char *str)
{
	int i;
	int flag = 1;
	int stringcount = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && flag == 1)
		{
			stringcount += 1;
			flag = 0;
		}
		if (str[i + 1] == ' ')
			flag = 1;
	}
	return (stringcount);
}
/**
 * tokenizer - takes a string and parses it into an array of strings (tokens)
 * @buffer: string to be tokenized
 * Return: pointer to an array of strings (tokens)
 */
char **tokenizer(char *buffer)
{
	char *token;
	int i = 0, stringcount = 0;
	char *delimiter = " \n";
	char **tokenArray;

	stringcount = _strcount(buffer);
	if (!stringcount)
		return (NULL);
	/* +1 to put null as end of array (used for cycling/searching) */
	tokenArray = malloc((stringcount + 1) * sizeof(char *));
	if (tokenArray == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		tokenArray[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	tokenArray[i] = NULL;
	return (tokenArray);
}
/**
 * _read - reads a single line from stdin, removes the newline character,
 * and returns a pointer to the string
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
/**
 * _strcmpPATH - compares PATH with environ array to confirm match
 * @s1: pointer to PATH string
 * @s2: pointer to environ string
 * Return: 0 on success
 */
int _strcmpPATH(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s2[i] != '='; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}
/**
 * _getenv - searches through environ for
 * a certain environment variable
 * (we will be looking for the PATH)
 * and returns a pointer to the location 
 * of the environment variable if it finds it.
 * @name: name of the environment variable to retrieve
 * Return: environment variable
 */
char *_getenv(const char *name)
{
	int i, result;

	for (i = 0; environ[i]; i++)
	{
		result = _strcmpPATH(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}
/**
 * main: function that runs the framework of the shell
 * Return: 0 on success
 */
int main(void)
{
	char *PATH = NULL;
	ssize_t writecount = 0;
	char *prompt = ";] ";
	char **tokenArray;
	char *buffer = NULL;

	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			writecount = write(STDOUT_FILENO, prompt, 2);  
			if (writecount == -1)
				exit(0);
		}

		tokenArray = NULL;
		buffer = _read();
		if (*buffer != '\0')
		{
			tokenArray = tokenizer(buffer);
			if (tokenArray == NULL)
			{
				free(buffer);
				continue;
			}
		}
		else
			free(buffer);
	}
	return (0);
}
