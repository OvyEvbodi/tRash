#include "main.h"

extern char **environ;

struct stat sfile;

/**
 * _getenv - gets the absolute path of a command
 *
 * @path_arr:
 *
 * Return: a pointer to an absolute path
*/

char *_getenv(char *cmd, char *var)
{
	char **env = environ;
	char *path = NULL, **path_arr;
	char *tmp_full_path, *full_path;
	size_t i = 0, var_len = _strlen(var);

	/*get path from path_arr*/
	while (*env)
	{
		/*printf("%s\n\n", *env);*/
		if (_strncmp(*env, var, var_len) == 0)
		{
			path = *env + var_len + 1;
			break;
		}
		env++;
	}

	if (path == NULL)
		return (NULL);

	path_arr = _strtow(path);
	if (!path_arr)
		return (NULL);

	while (path_arr[i])
	{
		/*check if file is executable*/
		tmp_full_path = str_concat(path_arr[i++], "/");
		full_path = str_concat(tmp_full_path, cmd);
		free(tmp_full_path);
		printf(" new full path --> %s\n", full_path);
		stat(full_path, &sfile);
		printf("serial_no %lu\n", sfile.st_ino);
		if (sfile.st_ino)
			break;

		free(full_path);
	}
	printf("Found path: %s\n", full_path);

	for (i = 0; path_arr[i]; i++)
		free(path_arr[i]);
	free(path_arr);

	return (full_path);
}

char *_getcmd(char *cmd)
{
	char *path;

//	check if command is a path/filename
	if (_strchr(cmd, '/'))
		path = cmd;
	else
		path = _getenv(cmd, "PATH");

	return (path);
}

int main(void)
{
	char *path = _getcmd("ls"); //hardcoded for testing purposes.
	printf("path from main ---> %s\n", path);
	free(path);
	return (0);
}

