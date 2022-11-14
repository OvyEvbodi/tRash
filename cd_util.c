#include "main.h"

/**
 * update_var_for_cd - Updates environment variables after changing directory.
 * @head: Head pointer to linked list of environment variables.
 * @arr_tokens: Array of tokens.
 * @buffer: Commandline buffer.
 * @pwd: New present working directory.
 * @oldpwd: Old present working directory.
 */
void update_var_for_cd(env_node *head, char **arr_tokens, char *buffer,
		char *pwd, char *oldpwd)
{
	replace_env_node(head, "PWD", pwd);
	replace_env_node(head, "OLDPWD", oldpwd);
	free(oldpwd);
	free(buffer);
	free(arr_tokens);
}

