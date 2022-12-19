#include "main.h"

/**
 * _getenv - searches through environ for
 * a certain environment variable
 * (we will be looking for the PATH)
 * and returns a pointer to the location
 * of the environment variable if it finds it
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
 * _strcmpPATH - compares PATH with environ array to confirm match
 * @s1: pointer to PATH string
 * @s2: pointer to environ string
 * Return: 0 on success
 */
int _strcmpPATH(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s2[i] != '='; i++) /* pull PATH before =, ex. 'PATH=' */
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}
