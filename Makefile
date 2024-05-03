CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = -lm

# Directory structure
SRC_DIR = lib
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib
TEST_DIR = tests

# Source files
LIB_SRCS = $(wildcard $(SRC_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

# Object files
LIB_OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(LIB_SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRCS))

# Library name
LIB_NAME = kilo
# Executable name
TEST_EXEC = kilo_filesystem

.PHONY: all clean

all: $(BUILD_DIR) $(LIB_DIR) $(BUILD_DIR)/$(LIB_NAME).a $(BUILD_DIR)/$(TEST_EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(BUILD_DIR)/$(LIB_NAME).a: $(LIB_OBJS)
	ar rcs $@ $^

$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJS) $(BUILD_DIR)/$(LIB_NAME).a
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

