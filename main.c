/**
 * main: 
 * @argc:
 * @argv:
 * @envp:
 * Return: 
 */

int main(argc, **argv, **envp)
{
	char *buffer = NULL;
	size_t size = 0;
	char **args = NULL;
	char *token = NULL;
	int readsize = 0;
	x = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", stdin);
		getline (&buffer, &size, stdin);
	}

	readsize = getline(&buffer, &size, stdin);
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		args[x] = _strdup(token);
		token = strtok(NULL, " ");
		x++;
	}

	char **tokens = NULL;

	typedep struct alia {
		char *name;
		int (*func)(void);
	} alias;

	alias aliases[] = {
		{"name", function},
		{NULL, NULL}
	};

	x = 0;
	while (aliases[x].name != NULL)
	{
		if (_strcmp(args[0], aliases[x].name) == 0)
			return (aliases[x].func);
		x++;
	}

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
	// execve("/usr/bin/ls", //
	// tokens[0] = "ls"
	// tokens[1] = "-l"
	// tokens[2] = "*.c",
	// extern char environ);

	//need to figure out how wait will work
	int wait_child;

	else
		waitpid(&wait_child);
}
