
# gcc or clang haven't decided
CC = gcc

CFLAGS := -Wall -Werorr -Wextra

BUILD_DIR = build/

# platform dependent, .dylib mac, .a linux, .dll windows.
LIB = test.a
INC = -Iinclude

SRCS =	$(wildcard lib/*.c)

OBJS = $(pathsubst src/%.c, build/%.c, $(SRCS))

build/%.o: lib/%.c | build
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


.PHONY: clean

$(LIB): $(OBJS)
	ar rcs $@ $^

build: 
	mkdir -p build
clean: 
	rm -rf $(BUILD_DIR)/*