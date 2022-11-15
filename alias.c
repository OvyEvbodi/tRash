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


int main(void)
{
	char *alias = NULL, *expanded = NULL;
	int shrt_len = 0, full_len = 0;

	printf("%s %s\n", alias, expanded);
	split_alias("push=smore and", &alias, &expanded, &shrt_len, &full_len);
	printf("\n%s %s\n", alias, expanded);
	printf("%d %d\n", shrt_len, full_len);
}