# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRC = src
OBJ = obj
BIN = bin
LIB = lib

# Files
MAIN_SRC = $(SRC)/main.c
MAIN_OBJ = $(OBJ)/main.o
LIB_SRCS = $(SRC)/mystrfunctions.c $(SRC)/myfilefunctions.c
LIB_OBJS = $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
STATIC_LIB = $(LIB)/libmyutils.a
TARGET = $(BIN)/client_static

# Default target
all: $(TARGET)

# Link main program with static library
$(TARGET): $(MAIN_OBJ) $(STATIC_LIB) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(STATIC_LIB)

# Build static library
$(STATIC_LIB): $(LIB_OBJS) | $(LIB)
	ar rcs $@ $(LIB_OBJS)

# Compile main.c
$(OBJ)/main.o: $(MAIN_SRC) | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile library source files
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

$(LIB):
	mkdir -p $(LIB)

# Clean build
clean:
	rm -rf $(OBJ)/*.o $(TARGET) $(STATIC_LIB)

