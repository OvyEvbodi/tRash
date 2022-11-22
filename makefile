tRash: makefile main.h tRash.c  _strtok.c _strcmp.c _getline.c _realloc.c builtins.c _atoi.c checks.c echo.c end.c get.c execve.c write_to_stderr.c  conv_to_char.c env2.c env.c handle_cmds.c cd_util.c  string_funcs.c string_funcs_2.c read_cmd_from_file.c
	sudo apt install gcc && sudo apt install binutils;
	gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 -o tRash tRash.c _strtok.c  _strcmp.c _getline.c  _realloc.c builtins.c _atoi.c checks.c echo.c end.c get.c execve.c write_to_stderr.c env2.c env.c cd_util.c handle_cmds.c conv_to_char.c  string_funcs.c string_funcs_2.c read_cmd_from_file.c;
	sudo mv tRash /usr/bin/;
	sudo mkdir -p /usr/local/man/man1/;
	sudo cp tRash.1 /usr/local/man/man1/;
	sudo gzip /usr/local/man/man1/tRash.1;
	sudo mandb;
