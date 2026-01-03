CC=gcc
CFLAGS=-Wall -Wextra -g
TARGET=elfinspect

SRC=src/main.c src/elf_loader.c
INC=-Iinclude

all:
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $(TARGET)

clean:
	rm -f $(TARGET)
	
