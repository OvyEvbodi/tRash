#include "main.h"

/**
 * main - entry point 
 * Description: test setenv feature
 *
 * Return: 0 always
*/

extern char **environ;

char *_getenv(char *var, char **env)
{
	char *var_val = NULL;
	size_t var_len = _strlen(var);

	while (*env)
	{
		if (_strncmp(*env, var, var_len) == 0)
		{
			var_val = *env + var_len + 1;
			break;
		}
		env++;
	}

	return (var_val);
}

int main(void)
{
	extern char **environ;
	char **env = environ;
	int i = 0;

	setenviron("PWD","/tragic/magic", 1);
	setenviron("USER","Gucci", 1);

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);
	return (0);
}