#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

/* execute fucntion */
int execute(char *buf, int line_st, char *name, int ct, char **env);

/* string functions */
char *_memset(char *s, char b, unsigned int n);
int remove_spaces(char *str);
char *_strcat(char *dest, char *src);
void SIGINTfunction(int sig_num);
int _strcmp(char *s1, char *s2);
void print_num(int count);
char *_strcpy(char *dest, const char *src);
int string_length(char *s);
int _putchar(char c);
int split_string(char *buffer, char **array, int read);

/* other functions */
char *_getenv(char **env, const char *name);
int _setenv(char **env, const char *name, const char *value, int overwrite);
int builtin_check(char **av, char **env);
int check_argv(char *av0, char *f_av, char **env);

#endif
