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
ssize_t _getline(char **line_buff, ssize_t *capacity, size_t stream);
/* updated getline */
ssize_t __getline(char **line_buff, size_t *capacity, FILE *stream);
/********************/
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);
size_t _strlen(char *str);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char **_strtow(char *str);
char *_strcpy(char *, char *);
char *_strdup(char *);
char *str_concat(char *, char *);
int _strncmp(char *, char *, size_t);

#endif /*MAIN_H*/
