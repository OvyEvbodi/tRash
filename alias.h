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
	char *pre:2;
	char *post:1;
} alias

/* prototypes */

#endif /*ALIAS_H*/