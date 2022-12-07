#define MAIN_H
#ifndef MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

extern char environ;

int main(argc, **argv, **envp);
char *_getenv(const char *name);
int _PATHstrcmp(const char *s1, const char *s2);
char *_read(void);
char **tokenizer(char *buffer);
int _strcount(char *str)
char *_strdup(char *str)
//helper functions
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif