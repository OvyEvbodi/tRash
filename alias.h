#ifndef ALIAS_H
#define ALIAS_H

/**
 * struct alias - defines an alias
 * @cmd: the alias command
 * @shrt: the short form
 * @full: the full command to expand shrt into
 * @pre: the prefix for printing the expanded command
 * @post: the postfix for printing the expanded command
*/


typedef struct aliases {
	char *cmd;
	char *shrt;
	char *full;
	struct aliases *link;
	char equal;
	char pre;
	char post;
} alias_t;

/* prototypes */
void split_alias(char *alias_str, char **alias, char **expanded, int *shrt_len, int *full_len);
alias_t *add_alias(alias_t **head, char **alias, char **expanded);
char *print_alias(char *head);


#endif /*ALIAS_H*/