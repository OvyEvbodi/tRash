#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include "main.h"

void check_signal(int sig, void (*handler)(int))
{
	int reval;
	struct sigaction action;

	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	reval = sigaction(sig, &action, NULL);
	if (reval == -1)
		perror("Error");
}

void handle_INT(int sig)
{
}


int main(int ac, char **av)
{
	char *buffer, *token, **arr_tokens;
	size_t len;
	int status, i;
	static unsigned int counter = 0;

	check_signal(SIGINT, handle_INT);
	while (1)
	{
		buffer = NULL;
		len = 0, i = 0;
		write(1, "tRash-->$ ", 10);

		if (__getline(&buffer, &len, stdin) == -1)
		{
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (buffer[0] == '\n')
		{
			free(buffer);
			continue;
		}

		arr_tokens = malloc(64 * sizeof(char *));
		if (!arr_tokens)
		{
			perror("Failed to readline");
			free(buffer);
			continue;
		}

		token = _strtok(buffer, "  \t\r\n");
		arr_tokens[i++] = token;
		while (token)
		{
			token = _strtok(NULL, " \t\r\n");
			arr_tokens[i++] = token;
		}
		arr_tokens[i] = NULL;

		if (!strcmp(arr_tokens[0], "exit"))
		{
			free(arr_tokens);
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		if (!strcmp(arr_tokens[0], "cd"))
		{
			if (!chdir(arr_tokens[1]))
			{
				free(buffer);
				free(arr_tokens);
				continue;
			}
			else
				perror("can't change dir");
			free(buffer);
			free(arr_tokens);
			continue;
		}

		ssize_t pid = fork();
		if (!pid)
		{
			if (execve(arr_tokens[0], arr_tokens, NULL) == -1)
			{
				dprintf(2, "%s: %u: not found\n", av[0], ++counter);
				free(arr_tokens);
				free(buffer);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			free(arr_tokens);
			free(buffer);
		}
	}
	return (0);
}

