simple_shell: tRash.c  _strtok.c _strcmp.c _getline.c _realloc.c builtins.c _atoi.c checks.c echo.c end.c get.c execve.c write_to_stderr.c  conv_to_char.c 
	gcc -o simple_shell tRash.c _strtok.c  _getline.c  _realloc.c builtins.c _atoi.c checks.c echo.c end.c get.c execve.c write_to_stderr.c env2.c env.c cd_util.c handle_cmds.c conv_to_char.c 
