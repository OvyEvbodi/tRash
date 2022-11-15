#ifndef ALIAS_H
#define ALIAS_H

/**
 * struct alias - defines an alias
 * @alias: the alias command
 * @shrt: the short form
 * @full: the full command to expand shrt into
 * @pre: the prefix for printing the expanded command
 * @post: the postfix for printing the expanded command
*/


typedef struct aliases {
	char *alias;
	char *shrt;
	char *full;
	char equal;
	char pre;
	char post;
} alias;

/* prototypes */
void split_alias(char *alias_str, char **alias, char **expanded, int *shrt_len, int *full_len);
char *print_alias(char *head);


#endif /*ALIAS_H*/