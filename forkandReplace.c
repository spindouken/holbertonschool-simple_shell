#include "main.h"

/**
 * _forkandReplace - forks a process and if the child process is successful
 * it executes the command, but if the child process fails
 * prints an error message and exits
 * @tokenArray: array of tokenized arguments passed to the program from stdin
 * @CLIbuffer: buffer that contains the command line input (CLI)
 * @commandPATHbuffer: full path of the command to be executed
 * Return: exit status of the child process
 */
int _forkandReplace(char **tokenArray, char *CLIbuffer, char *commandPATHbuffer)
{
	int i, status, errorReturnCheck, exitstatus = 0;
	pid_t pid;

	/**
	 * Fork process, if the child process is successful execute the command,
	 * if the child process fails print an error message and exit
	*/
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		errorReturnCheck = execve(commandPATHbuffer, tokenArray, environ);
		if (errorReturnCheck == -1)
		{
			perror(tokenArray[0]);
			for (i = 0; tokenArray[i]; i++)
			free(tokenArray[i]);
			free(tokenArray);
			free(CLIbuffer);
			exit(127); /*exit code 127 - command not found in PATH or builtin*/
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	/* Free the memory allocated for the command. */
	for (i = 0; tokenArray[i]; i++)
		free(tokenArray[i]);
	free(tokenArray);
	free(CLIbuffer);
	return (exitstatus);
}
