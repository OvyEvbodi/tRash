CC		:= gcc
GFLAGS		:= -g
CFLAGS		:= -Wall -Werror -pedantic -std=gnu89
CFILES		:= ../src/tRash.c ../src/_strtok.c ../src/_strcmp.c ../src/_getline.c ../src/_realloc.c \
		   ../src/builtins.c ../src/_atoi.c ../src/checks.c ../src/echo.c ../src/end.c ../src/get.c  \
		   ../src/execve.c ../src/write_to_stderr.c ../src/conv_to_char.c ../src/env2.c ../src/env.c \
		   ../src/handle_cmds.c ../src/cd_util.c ../src/string_funcs.c ../src/string_funcs_2.c ../src/read_cmd_from_file.c
CHEADERS	:= ../include/tRash.h
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
	sudo cp ../$(MAN_FILE) $(MAN_LOCATION)
	sudo gzip $(MAN_LOCATION)/$(MAN_FILE)
	sudo mandb;

clean:
ifneq ("$(wildcard $(PATH_TO_FILE))","")
	sudo rm $(PATH_TO_FILE)
else
	rm $(RM_FLAGS) $(TARGET)
endif
