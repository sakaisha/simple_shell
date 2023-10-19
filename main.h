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
void SIGINTfunction(int sig_int);
int _strcmp(char *str_1, char *str_2);
void print_num(int num);
char *_strcpy(char *dest, const char *src);
int string_length(char *str);
int _putchar(char c);
int split_string(char *str, char **str_array, int n);

/* other functions */
char *_getenv(char **env, const char *name);
int builtin_check(char **av, char **env);
int check_argv(char *av_0, char *actual_command, char **env);

#endif
