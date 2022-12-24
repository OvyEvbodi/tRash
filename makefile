CC		:= gcc
GFLAGS		:= -g
CFLAGS		:= -Wall -Werror -pedantic -std=gnu89
CFILES		:= tRash.c  _strtok.c _strcmp.c _getline.c _realloc.c builtins.c _atoi.c \
		   checks.c echo.c end.c get.c execve.c write_to_stderr.c  conv_to_char.c \
		   env2.c env.c handle_cmds.c cd_util.c  string_funcs.c string_funcs_2.c   \
		   read_cmd_from_file.c
CHEADERS	:= main.h
TARGET		:= tRash
STD_DEST	:= /usr/local/bin/
MAN_LOCATION	:= /usr/local/man/man1
MAN_FILE	:= tRash.1
RM_FLAGS	:= -rf
PATH_TO_FILE	:= /usr/local/bin/tRash

build: $(CHEADERS) $(CFILES)
	$(CC) $(GFLAGS) $(CFLAGS) -o $(TARGET) $(CFILES)

.PHONY: $(TARGET) clean
$(TARGET):
	sudo mkdir -p $(STD_DEST)
	sudo mv $(TARGET) $(STD_DEST)
	export PATH=$(STD_DEST)/$(TARGET):$(PATH)
	sudo mkdir -p $(MAN_LOCATION)
	sudo cp $(MAN_FILE) $(MAN_LOCATION)
	sudo gzip $(MAN_LOCATION)/$(MAN_FILE)
	sudo mandb;

clean:
ifneq ("$(wildcard $(PATH_TO_FILE))","")
	sudo rm $(PATH_TO_FILE)
else
	rm $(RM_FLAGS) $(TARGET)
endif
