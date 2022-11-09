#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

#define BUFF_SIZE	1024
#define NO_VALID_CHAR	0
#define VALID_CHAR	1
#define NO		0
#define YES		1

/**
 * struct cmd - defines a command
 * @name: the name of the command
 * @op: the function pointer to the operation to be performed
*/

typedef struct command
{
	char *name;
	char *(*op)(char **arr_tokens, char **env, char *buffer);
} cmds;

static int status;

/*prototypes for builtin functions*/
char *_exit_th(char **arr_tokens, char **env, char *buffer);
char *cd(char **arr_tokens, char **env, char *buffer);
char *_setenv(char **arr_tokens, char **env, char *buffer);
char *_putenv(char **arr_tokens, char **env, char *buffer);
char *builtins(char **arr_tokens, char **env, char *buffer);

/* main */
ssize_t _getline(char **line_buff, size_t *capacity, FILE *stream);
char *_strtok(char *str, const char *delim);
char *_getenv(char *var, char **env);
char *full_cmd(char *cmd, char *path);
char *_getcmd(char *cmd, char **arr_tokens, char **env);
char *sort_echo(char ***arr_tokens, char **env);
char *conv_to_char(size_t num);
void eof(char *buffer);
void error_exit(char *msg);
char *get_tokens(char *buffer, char ***arr_tokens);
void exit_sh(char **arr_tokens, char *buffer);
void exit_fail(char *msg, char *buffer, char **arr_tokens);
void exec_cmd(char *buffer, char **arr_tokens, char *cmd_full_path, char **env);

/* utilities */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
int _strncmp(char *, char *, size_t);
size_t _strlen(char *str);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char **_strtow(char *str);
char *_strcpy(char *, char *);
char *_strdup(char *);
char *str_concat(char *, char *);
char *_strstr(char *haystack, char *needle, int *i);
int _atoi(char *s);
char *vars(char **arr_tokens, char **env);

#endif /*MAIN_H*/
