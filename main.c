#include "main.h"

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

char **tokenize(char *buffer)
{
	char *token;
	int i = 0, stringcount = 0;
	char *delimiter = " \n";
	char **tokenArray;

	stringcount = _strcount(buffer);
	if (!stringcount)
		return (NULL);
    //+1 to put null as end of array (used for cycling/searching)
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

int _PATHstrcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s2[i] != '='; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

char *_getenv(const char *name)
{
	int i, result;

	for (i = 0; environ[i]; i++)
	{
		result = _PATHstrcmp(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

/**
 * main: 
 * Return: 
 */

int main(void)
{
	char *buffer = NULL;
	size_t size = 0;
	char **args = NULL;
	char *token = NULL;
	int readsize = 0;
	int prompt = ";]";
	ssize_t writecount = 0;
	x = 0;
	char *PATH = NULL;

	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			writecount = write(STDOUT_FILENO, prompt, stdin);  
			if (writecount == -1)
				exit(0);
		}
		buffer = _read();
		if (*buffer != '\0')
		{
			av = tokenize(buffer);
			if (av == NULL)
			{
				free(buffer);
				continue;
			}
			// token = strtok(buffer, " ");
			// while (token != NULL)
			// {
			// 	args[x] = _strdup(token);
			// 	token = strtok(NULL, " ");
			// 	x++;
			// }

			// char **tokens = NULL;

			// typedef struct alia {
			// 	char *name;
			// 	int (*func)(void);
			// } alias;

			// alias aliases[] = {
			// 	{"name", function},
			// 	{NULL, NULL}
			// };

			// x = 0;
			// while (aliases[x].name != NULL)
			// {
			// 	if (_strcmp(args[0], aliases[x].name) == 0)
			// 		return (aliases[x].func);
			// 	x++;
			// }

			char *path = "/usr/bin/ls";

			struct stat st;

			//take in token[0] string as first argument,//
			//and the address of a built-in struct st//
			//return 0 if it found token[0] in the evn variable $PATH//
			if (stat(tokens[0], &st) != 0);

			//fork takes no argumenets and returns pid if//
			//we are currently in the parent process,//
			//or 0 if we are inside the child process//
			pid_t pid = 0;
			pid = fork();

			int execute = 0;
			if (pid == 0)
			{
				execute = execve(path, tokens, environ);
			}
			//so far execve should look like below//
			// execve("/usr/bin/ls",
			// tokens[0] = "ls"
			// tokens[1] = "-l"
			// tokens[2] = "*.c",
			// extern char environ);
a
			//need to figure out how wait will work
			// pid_t child_pid;
			// pid_t wait_result;
			// int stat_loc;

			// old code
			// int wait_child;

			// else
			//    waitpid(&wait_child);

			child_pid = fork();

			// The child process
			if (child_pid == 0)
			{
			printf("### Child ###\nCurrent PID: %d and Child PID: %d\n",
			getpid(), child_pid);
			sleep(1); // Sleep for one second
			} 
			else
			{
			wait_result = waitpid(child_pid, &stat_loc, WUNTRACED);
			printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n",
			getpid(), child_pid);
			}
		}
	}
	return (0);
}
