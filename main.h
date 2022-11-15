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
#include <errno.h>

#define BUFF_SIZE	1024
#define NO_VALID_CHAR	0
#define VALID_CHAR	1
#define NO		0
#define YES		1

/* echo */
#define PID		1
#define STAT		2
/***************************/


/**** for env ****/

/**
 * struct env - defines an environment variable
 * @name: the name of the variable
 * @equals: an equal to symbol
 * @value: the value of the variable
 * @next: the next node
*/

typedef struct env
{
	char *name;
	char *equals;
	char *value;
	struct env *next;
} env_node;

env_node *env_list(char **env);
env_node *create_env_list(env_node **head, char *name, char *value);
env_node *create_env_node(char *name, char *value);
env_node *add_to_existing(env_node **head, char *name, char *value);
env_node *replace_env_node(env_node *node, char *name, char *value);
char *delete_env_node(env_node *node, char *name);
void free_env_list(env_node *head);
/***************************/

/**
 * struct command - defines a command
 * @name: the name of the command
 * @op: the function pointer to the operation to be performed
*/

typedef struct command
{
	char *name;
	char *(*op)(char **arr_tokens, env_node *env_head, char *buffer);
} cmds;

extern char **environ;

/* _getline */
ssize_t _getline(char **line_buff, size_t *capacity, ssize_t fd);

/* _strtok */
char *_strtok_and_cmnt(char *str, const char *delim);

/* read_cmd_from_file */
void read_cmd_from_file(env_node *env_head, char *av, char *av1);

/*prototypes for builtin functions*/
char *_exit_th(char **arr_tokens, env_node *env_head, char *buffer);
char *cd(char **arr_tokens, env_node *env_head, char *buffer);
char *_setenv(char **arr_tokens, env_node *env_head, char *buffer);
char *_unsetenv(char **arr_tokens, env_node *env_head, char *buffer);
char *_env(char **arr_tokens, env_node *env_head, char *buffer);

/* execve */
void exec_cmd(char *buffer, char **arr_tokens, char *cmd_full_path,
		env_node *env_head);
void free_for_execve(char *cmd, char *echo_arg_string, char *buff,
		char **arr_tokens, char **_env);
char **arrange_environ(char **_environ, env_node *head);
void free_environ(char **env);

/* get */
char *get_tokens(char *buffer, char ***arr_tokens, env_node *head);
char *_getenv(char *var, env_node *env_head);
char *full_cmd(char *cmd, char *path);
char *_getcmd(char *cmd, char **arr_tokens, env_node *env_head);

/* handle_cmds */
char *handle_cmds(env_node *env_head, char *av, char *buffer,
		size_t *loop_count);

/* checks */
void check_mul_cmds(env_node *env_head, char *av, char *buffer,
		size_t *loop_count);
char *check_builtins(char **arr_tokens, env_node *env_head, char *buffer);

/* echo */
char *sort_echo(char ***arr_tokens, env_node *env_head, int stat);
void handle_esc(char ***arr_tokens, char **string, size_t *str_len, size_t i,
		size_t *j);
char *mov_num_vals(char **string, size_t *str_len, size_t *str_size,
		size_t type, size_t *j, size_t *doll_flag, int stat);
char *mov_var_val(char ***arr_tokens, env_node *env_head, char **string,
		size_t *str_len, size_t *j, size_t i, size_t *doll_flag);
char *handle_exp(char ***arr_tokens, env_node *env_head, char **string,
		size_t *str_len, size_t *str_size, size_t *j, size_t i, size_t *doll_flag, int stat);

/* end */
void eof(char *buffer, env_node *env_head, char flag);
void error_exit(char *msg, env_node *env_head);
void exit_sh(char **arr_tokens, char *buffer, env_node *env_head);
void exit_fail(char *msg, char *buffer, char **arr_tokens, env_node *env_head);

/* utilities */
int write_to_stderr(char *format, char *arg_zero, size_t loop_count,
		char *tok_zero, char *tok_one);
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
char *_strstr(char *haystack, char *needle);
char *conv_to_char(size_t num);
int _atoi(char *s);
int exit_atoi(char *s);
void update_var_for_cd(env_node *head, char **arr_tokens, char *buffer,
		char *pwd, char *oldpwd);

#endif /* for MAIN_H */
