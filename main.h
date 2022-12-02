#define MAIN_H
#ifndef MAIN_H

#include <stdio.h>

int main(argc, **argv, **envp);
//helper functions
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif