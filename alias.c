//#include "alias.h"
#include "main.h"


/**
 * alias_strlen - calculates the length of an alias definition
 * and its expansion
 * @alias_str: the string defining an alias
 *
 * Return: void
*/

void alias_strlen(char *alias_str)
{
	static int shrt_len, full_len;
	int i = 0;
	char full[BUFF_SIZE];
	char shrt[BUFF_SIZE / 4];

	while (alias_str[i])
	{
		if (alias_str[i] == '=')
		{
			i++;
			if (alias_str[i] == '\'' || alias_str[i] == '"')
			{
				i++;
				for (full_len = 0; alias_str[i]; i++)
					full[full_len++] = alias_str[i];
				full[full_len - 1] = '\0';
				full_len--;
				break;
			}
			else
			{
				for (full_len = 0; alias_str[i] != ' ' && alias_str[i]; i++)
					full[full_len++] = alias_str[i];
				full[full_len] = '\0';
				break;
			}
		}
		shrt[shrt_len++] = alias_str[i++];
	}
	printf("short -> %s, len -> %d, full -> %s, len -> %d full_len\n", shrt, shrt_len, full, full_len);

}


int main(void)
{
	alias_strlen("push='smore and'");
}