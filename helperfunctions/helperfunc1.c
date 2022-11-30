#include "main.h"
/**
 *_strlen - entry function for string length
 *@s: String length value
 *Description: Function that returns length of string
 *Return: 0 = Success
 */
int _strlen(char *s)
{
	int charCount = 0;

	while (s[charCount] != '\0')
	{
		charCount++;
	}
	return (charCount);
}



/**
 * *_strcpy - copies the string
 * Descrption:  copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest
 * @src: char type string
 * @dest: char type string
 * Return: Pointer to 'dest'
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}



/**
 * _strcat - function that concatenates two strings
 * @dest: s2
 * @src: s1
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int one;
	int two;

	for (one = 0 ; dest[one] ; one++)
		;

		for (two = 0 ; src[two] ; two++)
		{
			dest[one] = src[two];
			one++;
		}
		return (dest);

}



/**
 * _strcmp - compare two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: compared values
 */

int _strcmp(char *s1, char *s2)
{
	int i, b;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}

	b = s1[i] - s2[i];
	return (b);
}
