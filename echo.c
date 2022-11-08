#include "main.h"

char *conv_to_char(size_t num)
{
	int i, valid, buff_ind = 0;
	char tmp_buff[7];
	char *buff = malloc(sizeof(char) * 8);

	if (!buff)
		return (NULL);

	if (num == 0)
	{
		buff[0] = '0';
		buff[1] = '\0';
		return (buff);
	}

	for (i = 0; i < 7; i++)
		tmp_buff[i] = '0';

	while (num)
	{
		tmp_buff[--i] = (num % 10) + 48;
		num /= 10;
	}

	valid = NO;
	i = 0;
	while (i < 7)
	{
		if (tmp_buff[i] > '0')
			valid = YES;
		if (valid)
			buff[buff_ind++] = tmp_buff[i];
		i++;
	}
	buff[buff_ind] = '\0';

	return (buff);
}

char *sort_echo(char ***arr_tokens, char **env)
{
	size_t i, j, pid_len, str_len = 0, str_size = BUFF_SIZE, started = NO;
	size_t status_val, stat_len, tmp_j, v_val_ind, var_ind;
	char *char_pid_mall, char_pid[8], *char_stat_mall, char_stat[8];
	char *var_val, var[BUFF_SIZE];
	char *string = malloc(sizeof(char) * BUFF_SIZE);

	if (!string)
		return (NULL);

	for (i = 1; arr_tokens[0][i]; i++)
	{
		if (started)
			string[str_len++] = ' ';
		started = YES;
		for (j = 0; arr_tokens[0][i][j]; j++)
		{
			if (arr_tokens[0][i][j] == '$')
			{
				if (arr_tokens[0][i][j + 1] == '$')
				{
					pid_len = 0;
					pid_t pid = getpid();
					char_pid_mall = conv_to_char(pid);
					while (char_pid_mall[pid_len])
					{
						char_pid[pid_len] = char_pid_mall[pid_len];
						pid_len++;
					}
					char_pid[pid_len] = '\0';
					free(char_pid_mall);
					for (pid_len = 0; char_pid[pid_len]; pid_len++)
					{
						if (str_len == str_size)
						{
							string = _realloc(string, str_size, str_size + BUFF_SIZE);
							if (string == NULL)
								return (NULL);
							str_size += BUFF_SIZE;
						}
						string[str_len++] = char_pid[pid_len];
					}
					j++;
					continue;
				}
				else if (arr_tokens[0][i][j + 1] == '?')
				{
					stat_len = 0;
					status_val = WIFEXITED(status);
					char_stat_mall = conv_to_char(status_val);
					while (char_stat_mall[stat_len])
					{
						char_stat[stat_len] = char_stat_mall[stat_len];
						stat_len++;
					}
					char_stat[stat_len] = '\0';
					free(char_stat_mall);
					for (stat_len = 0; char_stat[stat_len]; stat_len++)
					{
						if (str_len == str_size)
						{
							string = _realloc(string, str_size, str_size + BUFF_SIZE);
							if (string == NULL)
								return (NULL);
							str_size += BUFF_SIZE;
						}
						string[str_len++] = char_stat[stat_len];
					}
					j++;
					continue;
				}
				else if (arr_tokens[0][i][j + 1] == '\0')
				{
					string[str_len++] = '$';
					j++;
					continue;
				}
				else
				{
					var_ind = 0;
					v_val_ind = 0;
					for (tmp_j = j + 1;
						(arr_tokens[0][i][tmp_j] >= 'a' && arr_tokens[0][i][tmp_j] <= 'z')
							|| (arr_tokens[0][i][tmp_j] >= 'A' && arr_tokens[0][i][tmp_j] <= 'Z');
						tmp_j++)
					{
						var[var_ind++] = arr_tokens[0][i][tmp_j];
					}
					var[var_ind] = '\0';
					var_val = _getenv(var, env);
					if (var_val)
						while (var_val[v_val_ind])
							string[str_len++] = var_val[v_val_ind++];
					j = tmp_j - 1;
					continue;
				}
			}
			string[str_len++] = arr_tokens[0][i][j];
		}
	}
	string[str_len] = '\0';
	arr_tokens[0][1] = string;
	arr_tokens[0][2] = NULL;
	return (string);
}

