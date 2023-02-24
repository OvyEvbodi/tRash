CC             := gcc
CFLAGS         := -g -Wall -Werror -pedantic -std=gnu89
SRC_DIR        := ../src
INC_DIR        := ../include
OBJ_DIR        := obj
CFILES         := $(wildcard $(SRC_DIR)/*.c)
OBJS           := $(addprefix $(OBJ_DIR)/,$(notdir $(CFILES:.c=.o)))
TARGET         := tRash
STD_DEST       := /usr/local/bin/
MAN_LOCATION   := /usr/local/man/man1
MAN_FILE       := tRash.1
RM             := rm -f
PATH_TO_TARGET := /usr/local/bin/tRash

.PHONY: clean all

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^

${OBJS}: | ${OBJ_DIR}

${OBJ_DIR}/%.o: $(SRC_DIR)/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} -I $(INC_DIR) -c -o $@ $<

${OBJ_DIR}:
	mkdir -p $@

install: ${TARGET}
	sudo mkdir -p ${STD_DEST}
	sudo mv ${TARGET} ${STD_DEST}
	export PATH=${STD_DEST}:${PATH}
	sudo mkdir -p ${MAN_LOCATION}
	sudo cp ../${MAN_FILE} ${MAN_LOCATION}
	sudo gzip ${MAN_LOCATION}/${MAN_FILE}
	sudo mandb;

clean:
	sudo ${RM} ${TARGET} ${OBJS} ${PATH_TO_TARGET}

uninstall: ${PATH_TO_TARGET}
	sudo ${RM} ${PATH_TO_TARGET}

${PATH_TO_TARGET}:
	${RM} ${TARGET}
	sudo ln -s `pwd`/${TARGET} ${PATH_TO_TARGET}
