CC = gcc

# Flags for compiling C source files
CFLAGS = -Wall -Wextra -std=c11 -g -I./src  # path adjusted for src directory

# Executable name
EXEC = raycast

# Object files
SRC = $(wildcard src/*.c)  # Pattern to find source files in src directory
OBJS = $(SRC:.c=.o)

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lSDL2 -lSDL2_image  # Link with SDL2 and SDL2_image libraries

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

