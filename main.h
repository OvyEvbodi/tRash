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

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **line_buff, ssize_t *capacity, size_t stream);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);
size_t _strlen(char *str);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char **_strtow(char *str);

#endif /*MAIN_H*/
