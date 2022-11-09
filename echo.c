#include "main.h"

/**
 * conv_to_char - Converts the pid and status integers to characters.
 * @num: Integer value to convert.
 *
 * Return: Buffer containing the characters.
 */
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

/**
 * mov_num_vals - Moves the converted numbers to the growing string.
 * @string: Pointers to growing string.
 * @str_len: Pointer to string length count.
 * @str_size: Pointer to size of the string.
 * @type: Says whether to get pid (for $) or get status (for ?).
 * @j: Pointer to the index in token.
 * @doll_flag: Helps to know when to start space seperating in string.
 *
 * Return: Returns ok on success, NULL on error.
 */
char *mov_num_vals(char **string, size_t *str_len, size_t *str_size,
		size_t type, size_t *j, size_t *doll_flag)
{
	char *char_tmp_malloc, char_tmp[8];
	size_t num_len = 0;
	pid_t num;

	if (type == PID)
		num = getppid();
	else if (type == STAT)
		num = WIFEXITED(status);

	char_tmp_malloc = conv_to_char(num);
	while (char_tmp_malloc[num_len])
	{
		char_tmp[num_len] = char_tmp_malloc[num_len];
		num_len++;
	}
	char_tmp[num_len] = '\0';
	free(char_tmp_malloc);

	for (num_len = 0; char_tmp[num_len]; num_len++)
	{
		if (*str_len == *str_size)
		{
			*string = _realloc(*string, *str_size, *str_size + BUFF_SIZE);
			if (*string == NULL)
				return (NULL);
			*str_size += BUFF_SIZE;
		}
		(*doll_flag)++;
		string[0][(*str_len)++] = char_tmp[num_len];
	}
	(*j)++;
	return ("ok");
}

/**
 * mov_var_val - Moves the values of variables to the growing string.
 * @arr_tokens: Pointer to the array of tokens.
 * @env: Array of environment variables.
 * @string: Pointer to growing string.
 * @str_len: Pointer to the string length count.
 * @j: Pointer to the index in a token in an array.
 * @i: Index of a token in an array.
 * @doll_flag: Helps to know when to start appending space in string.
 *
 * Return: ok if successful, NULL if error occurs.
 */
char *mov_var_val(char ***arr_tokens, char **env, char **string,
		size_t *str_len, size_t *j, size_t i, size_t *doll_flag)
{
	size_t var_ind = 0, v_val_ind = 0, tmp_j;
	char *var_val, var[BUFF_SIZE];

	for (tmp_j = *j + 1;
		(arr_tokens[0][i][tmp_j] >= 'a' && arr_tokens[0][i][tmp_j] <= 'z') ||
		(arr_tokens[0][i][tmp_j] >= 'A' && arr_tokens[0][i][tmp_j] <= 'Z') ||
		(arr_tokens[0][i][tmp_j] >= '0' && arr_tokens[0][i][tmp_j] <= '9') ||
		(arr_tokens[0][i][tmp_j] == '_');
		tmp_j++)
	{
		var[var_ind++] = arr_tokens[0][i][tmp_j];
	}
	var[var_ind] = '\0';
	var_val = _getenv(var, env);
	if (var_val)
		while (var_val[v_val_ind])
			string[0][(*str_len)++] = var_val[v_val_ind++], (*doll_flag)++;
	*j = tmp_j - 1;
	return ("ok");
}

/**
 * handle_exp - Finds out where to get the value for an expansion.
 * @arr_tokens: Pointer to array of tokens.
 * @env: Array of environment variables.
 * @string: Pointer to growing string.
 * @str_len: Pointer to length of growing string.
 * @str_size: Pointer to size of string.
 * @j: Pointer to current index in token in the array.
 * @i: Index of token in array.
 * @doll_flag: Helps to know when to start appending space in string.
 *
 * Return: ok if successful, NULL if error occurs.
 */
char *handle_exp(char ***arr_tokens, char **env, char **string,
		size_t *str_len, size_t *str_size, size_t *j, size_t i, size_t *doll_flag)
{
	char *reval;

	switch (arr_tokens[0][i][*j + 1])
	{
		case '$':
			reval = mov_num_vals(string, str_len, str_size, PID, j, doll_flag);
			if (!reval)
				return (NULL);
			break;
		case '?':
			reval = mov_num_vals(string, str_len, str_size, STAT, j, doll_flag);
			if (!reval)
				return (NULL);
			break;
		case '\0':
			doll_flag++;
			string[0][(*str_len)++] = '$';
			(*j)++;
			break;
		default:
			mov_var_val(arr_tokens, env, string, str_len, j, i, doll_flag);
	}
	return ("ok");
}

/**
 * sort_echo - Arranges the arguments to exec for the echo command.
 * @arr_tokens: Pointer to array of tokens.
 * @env: Array of environment variables.
 *
 * Return: ok if successful, NULL otherwise.
 */
char *sort_echo(char ***arr_tokens, char **env)
{
	size_t i, j, str_len = 0, str_size = BUFF_SIZE, started = NO;
	size_t doll_flag = 0;
	char *reval, *string = malloc(sizeof(char) * BUFF_SIZE);

	if (!string)
		return (NULL);

	for (i = 1; arr_tokens[0][i]; i++)
	{
		if (started && doll_flag)
			string[str_len++] = ' ';
		started = YES;
		for (j = 0; arr_tokens[0][i][j]; j++)
		{
			if (arr_tokens[0][i][j] == '$')
			{
				reval = handle_exp(arr_tokens, env, &string,
						&str_len, &str_size, &j, i, &doll_flag);
				if (!reval)
					return (NULL);
				continue;
			}
			string[str_len++] = arr_tokens[0][i][j];
			doll_flag++;
		}
	}
	string[str_len] = '\0';
	arr_tokens[0][1] = string, arr_tokens[0][2] = NULL;
	return (string);
}

