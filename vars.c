#include "main.h"

/**
 * vars - replaces variable arguments for the echo command
 * @vv:
 *
 * Return:
*/

//takeout
extern char **environ;

char *vars(char **arr_tokens, char **env)
{
	int i = 0, count, pid_ind = 9;
	char *tmp_buff, *haystack;
	char pid_buff[10], pid_temp[10];
	pid_t pid = getpid();

	//malloc has an issue
	tmp_buff = malloc(sizeof(char) * BUFSIZ);
	if (!tmp_buff)
		return (NULL);

	printf("pid -> %d pid_ind %d, buff -> %s \n", pid, pid_ind, pid_buff);

	while (pid)
	{
		pid_buff[pid_ind--] = (pid % 10) + 48;
		pid /= 10;

	}
	pid_ind++;
	while (pid_ind < 10 && pid_buff[pid_ind])
	{
		pid_temp[i++] = pid_buff[pid_ind++];
	}
	pid_temp[i] = '\0';
	//test = {'l', 'o', 'l'};
	i = 0;
	printf("pid -> %d pid_ind %d, buff -> %s\n", pid, pid_ind, pid_temp);
	for (;arr_tokens[i]; i++)
	{
		haystack = _strstr(arr_tokens[i], "$$", &count);
		if (haystack)
		{
			tmp_buff = haystack;
			//printf("-> temp bufs %s\n", tmp_buff);
			if (*(tmp_buff++) == '$')
			{
				tmp_buff++;
				haystack = pid_temp;
			}

			printf("%d and %d for %s... new -> %s\n", getpid(), count, haystack, tmp_buff);
		}
	}
	//free(tmp_buff);
	
	return ("ok");

}

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle, int *i)
{
	int j;

	for (*i = 0; haystack[*i] != '\0'; (*i)++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[*i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[*i]);
	}
	return (NULL);
}

int main(void)
{
	char **env = environ;
	char *arr_tokens[] = {"fhudsu$$","na", "$$ ego", "nil", "$$", "$$$$", "$$gucci", NULL};
	vars(arr_tokens, env);
}
