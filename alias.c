#include "alias.h"
#include "main.h"


/**
 * split_alias - calculates the length of an alias definition
 * and its expansion
 * @alias_str: the string defining an alias
 * @alias: the alias
 * @expanded: th command to expand alias into
 *
 * Return: void
*/

void split_alias(char *alias_str, char **alias, char **expanded, int *shrt_len, int *full_len)
{
	int i = 0;
	char full[BUFF_SIZE], shrt[BUFF_SIZE / 4];

	while (alias_str[i])
	{
		if (alias_str[i] == '=')
		{
			i++;
			if (alias_str[i] == '\'' || alias_str[i] == '"')
			{
				i++;
				for (*full_len = 0; alias_str[i]; i++)
					full[(*full_len)++] = alias_str[i];
					full[(*full_len) - 1] = '\0';
				(*full_len)--;
				break;
			}
			else
			{
				for (*full_len = 0; alias_str[i] != ' ' && alias_str[i]; i++)
					full[(*full_len)++] = alias_str[i];
				full[*full_len] = '\0';
				break;
			}
		}
		shrt[(*shrt_len)++] = alias_str[i++];
	}
	printf("short -> %s, len -> %d, full -> %s, len -> %d full_len\n", shrt, *shrt_len, full, *full_len);

	*alias = _strdup(shrt);
	*expanded = _strdup(full);

}

/**
 * add_alias - adds an alias definition to the alias list,
 * or overwrites an existing definition
 * @head: a pointer to the head pointer
 * @alias: the alias
 * @expanded: th command to expand alias into
 *
 * Return: a pointer to the new alias,
 * otherwise, NULL
*/


alias_t *add_alias(alias_t **head, char **alias, char **expanded)
{
	alias_t *new;
	alias_t *temp = *head;

	new = malloc(sizeof(alias_t));
	if (!new)
		return (NULL);
	new->cmd = "alias";
	new->shrt = _strdup(*alias);
	new->full = _strdup(*expanded);
	new->equal = '=';
	new->pre = '\'';
	new->post = '\'';
	new->link = NULL;

	if (!*head)
	{
		*head = new;
		return (new);
	}

	while (temp->link)
		temp = temp->link;
	temp->link = new;

	// free(alias);
	// free(expanded);

	return (new);
}


int main(void)
{
	char *alias = NULL, *expanded = NULL;
	int shrt_len = 0, full_len = 0;
	alias_t *head = NULL, *node;

	printf("%s %s\n", alias, expanded);
	split_alias("push='smore and'", &alias, &expanded, &shrt_len, &full_len);
	printf("\n%s %s\n", alias, expanded);
	printf("%d %d\n", shrt_len, full_len);
	node = add_alias(&head, &alias, &expanded);
	printf("%s, %s, %s, %c, %c \n", node->cmd, node->shrt, node->full, node->pre, node->equal);

}