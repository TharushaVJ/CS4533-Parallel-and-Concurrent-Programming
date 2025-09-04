CC      := gcc
CFLAGS  := -O2 -Wall -Wextra -std=c11
CPPFLAGS:= -Iinclude
LDFLAGS := -pthread

SRC := src/cli.c src/linked_list.c src/operations.c src/util.c src/worker.c main.c
OBJ := $(SRC:.c=.o)
BIN := lablist

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(BIN)