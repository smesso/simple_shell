#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);

char *get_path(char **env);
int _values_path(char **arg, char **env);
char *getline_command(void);
void print_environment(char **env);
char **get_tokens(char *lineptr);
void _exit_shell(char **args, char *lineptr, int _exit);
int execute_command(char **arg, char **av, char **env, char *lineptr, int np, int c)
char *lineptr, int np, int c);
char *_strtok(char *str, const char *delim);
char *duplicate_string(const char *str)

#endif /* SHELL_H */
