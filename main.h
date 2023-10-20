#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 250

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <limits.h>

/* execute fucntion */
int execute(char *buf, int line_st, char *name, int ct, char **env);
int prepare_execution(char *buff, int line_st, char *name, int loops_count,
		char **env, char ***av, char *func, int *result);
int execute_command(char **av, char *func, char *name, int ct);
void handle_command_not_found(char **av, char *name, int loops_count);
void handle_prompt(void);
int count_spaces(char *str);
void handle_eof(char *buff);
void handle_newline(void);
ssize_t _getline_trial(char **buff, size_t *n, FILE *stream);
int _fileno(FILE *stream);
ssize_t read_char_from_stream(char *c, FILE *stream);
ssize_t build_buffer(char **buff, size_t *n, char c,
		size_t *pos, int *ignore_line, int *word_started);

/* string functions */
char *_memset(char *s, char c, unsigned int n);
int remove_spaces(char *str);
char *_strcat(char *dest, char *src);
void SIGINTfunction(int sig_int);
int _strcmp(char *str_1, char *str_2);
void print_num(int num);
char *_strcpy(char *dest, const char *src);
int string_length(char *str);
int _putchar(char c);
int split_string(char *str, char **str_array, int n);
long string_to_integer(char *str);

/* other functions */
char *_getenv(char **env, const char *name);
int builtin_check(char **av, char **env, int loops_count);
int check_argv(char *av_0, char *actual_command, char **env);

#endif




