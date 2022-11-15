#ifndef ALIAS_H
#define ALIAS_H

/**
 * struct alias - defines an alias
 * @cmd: the alias command
 * @shrt: the short form
 * @full: the full command to expand shrt into
 * @pre: the prefix for printing the expanded command
 * @post: the postfix for printing the expanded command
 * @s_len: the length of shrt
 * @f_len: the length of full
 * @link: a link to the next alias node
*/


typedef struct aliases {
	char *cmd;
	char *shrt;
	char *full;
	struct aliases *link;
	int s_len;
	int f_len;
	char equal;
	char pre;
	char post;
} alias_t;

/* prototypes */
void split_alias(char *alias_str, char **alias, char **expanded, int *shrt_len, int *full_len);
alias_t *add_alias(alias_t **head, char **alias, char **expanded, int *shrt_len, int *full_len);
char *print_alias(alias_t *head);


#endif /*ALIAS_H*/