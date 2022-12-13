#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int main(void);
char *_getenv(const char *name);
int _strcmpPATH(const char *s1, const char *s2);
char *_read(void);
char **tokenizer(char *buffer);
int _strcount(char *str);
char *_strdup(char *str);
char *_commandPATH(char **tokenArray, char *PATH, char *copy);
int _countPATHdirectories(char *str);
char *_concatPATHloc(char *tmp, char **tokenArray, char *tok);
char *_memset(char *s, char b, unsigned int n);
int builtin_checker(char **tokenArray, char *buffer, int exitstatus);
int _printenv(void);
void _printstring(char *str);
int _putchar(char c);
int forkandReplace(char **tokenArray, char *buffer, char *commandPATHbuffer);

/* HELPER FUNCTIONS */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);

#endif
