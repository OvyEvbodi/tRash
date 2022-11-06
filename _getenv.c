#include "main.h"

extern char **environ;

struct stat sfile;

/**
 * _getenv - gets the absolute path of a command
 *
 * @env_ptr:
 *
 * Return: a pointer to an absolute path
*/

char *_getenv(char **env_ptr, char *cmd)
{
	char **env = environ;
	char *path = NULL, *full_path;
	//char **env_ptr;

	/*get path from env_ptr*/
	while (*env)
	{
		/*printf("%s\n\n", *env);*/
		if (**env == 'P' && *(*env + 1) == 'A' && *(*env + 2) == 'T' && *(*env + 3) == 'H' && *(*env + 4) == '=')
		{
			path = *env;
			//printf("%s\n", path);
			break;
		}
		env++;
	}

	if (*env_ptr == NULL)
		env_ptr = _strtow(path);
	//printf("%s \n", *env_ptr);
	*env_ptr = _strchr(*env_ptr, '/');
	//printf("%s \n", *env_ptr);

	env_ptr++;
	
	while (*env_ptr)
	{
		/*check if file is executable*/
		full_path = NULL;
		full_path = _strcat(*env_ptr, "/");
		full_path = _strcat(full_path, cmd);
		printf(" new full path --> %s\n", full_path);
		stat(full_path, &sfile);
		int perm = printf("serial_no %llo\n", sfile.st_ino);
		if (sfile.st_ino)
		{
			break;
		}
		
		printf("%s after search \n", *env_ptr);
		
		env_ptr++;
	}
	printf("%s \n", *env_ptr);
	env_ptr--; //take out!!! for testing only..

	//return (*env_ptr);
	return (full_path);
	
}

char *_getcmd(char *cmd)
{
	char **env_ptr;
	char *path;

	/*check if command is a path/filename*/
	if (_strchr(cmd, '/'))
		path = cmd;
	else
	{
	env_ptr = malloc(64 * sizeof(char *));
	if (!env_ptr)
	{
		printf("error\n");
		free(env_ptr);
		exit(EXIT_FAILURE);
	}

	path = _getenv(env_ptr, cmd);
	//handle return (-1)
	free(env_ptr);
	}
	return (path);
}

int main(void)
{
	char *path = _getcmd("ls"); //hardcoded for testing purposes. 
	printf("path from main ---> %s\n", path);
	return (0);
}