#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/* String printing */
int _putchar(char c);
int _strlen(char *s);
void print_number(int count);

/* Related to strings */
int split_string(char *buffer, char **array, int read);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
long _stoi(char *s);
int string_mod(char *str);
char *_memset(char *s, char b, unsigned int n);

/* New functions */
int check_argv(char *av0, char *f_av, char **env);
int handle_builtin(char **av, char *prev_directory, char **env, char *name, int count);
char *getenv(char **env, const char *name);
int setenv(char **env, const char *name, const char *value, int overwrite);
int change_directory(char *av2, char *pr_cwd, char **env, char *name, int ct, char **av);
void release_memory(char **av);
void handle_sigint(int sig_num);

/* Program executing function */
int execute_program(char *buf, int rd, char *name, char *p_cwd, int ct, char **env);

#endif
