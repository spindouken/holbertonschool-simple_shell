#include "main.h"

/**
 * tokenizer - takes a string and parses it into an array of strings (tokens)
 * @CLIbuffer: string to be tokenized
 * (buffer that contains the command line input (CLI))
 * Return: pointer to an array of strings (tokens)
 */
char **tokenizer(char *CLIbuffer)
{
	char *token;
	int i = 0, stringcount = 0;
	char *delimiter = " \n"; /* will tokenize CLI by space or newline */
	char **tokenArray;

	stringcount = _strcount(CLIbuffer);
	if (!stringcount)
		return (NULL);
	/* +1 to put null as end of array (used for cycling/searching) */
	tokenArray = malloc((stringcount + 1) * sizeof(char *));
	if (tokenArray == NULL)
		exit(1);
	token = strtok(CLIbuffer, delimiter);
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
			flag = 0; /* set flag to 0 indicating not at a space character */
		}
		if (str[i + 1] == ' ')
			flag = 1; /* at a space character */
	}
	return (stringcount);
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
		{ ; } /* getting length of str as i */

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
