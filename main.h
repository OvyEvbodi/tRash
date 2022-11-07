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
#define VALID_CHAR	1
#define NO_VALID_CHAR	0

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **line_buff, size_t *capacity, FILE *stream);
char *_strtok(char *str, const char *delim);
int _strcmp(char *s1, char *s2);
int _strncmp(char *, char *, size_t);
size_t _strlen(char *str);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char **_strtow(char *str);
char *_strcpy(char *, char *);
char *_strdup(char *);
char *str_concat(char *, char *);

char *_getenv(char *var, char **env);
char *full_cmd(char *cmd, char *path);
char *_getcmd(char *cmd, char **env);
void eof(char *buffer);
void error_exit(char *msg);
char *get_tokens(char *buffer, char ***arr_tokens);
int change_dir(char **arr_tokens, char **env);
void exit_sh(char **arr_tokens, char *buffer);
void exit_fail(char *msg, char *buffer, char **arr_tokens);
int check_builtins(char **arr_tokens, char *buffer, char **env);
void exec_cmd(char *buffer, char **arr_tokens, char *cmd_full_path, char **env);

#endif /*MAIN_H*/
