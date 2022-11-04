#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **line_buff, ssize_t *capacity, size_t stream);
int _strcmp(char *s1, char *s2);

#endif /*MAIN_H*/
