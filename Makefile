# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -Llib
LDLIBS = -lmyutils

# Directories
SRC = src
OBJ = obj
BIN = bin
LIB = lib
MAN = man/man3

# Files
MAIN_SRC = $(SRC)/main.c
MAIN_OBJ = $(OBJ)/main.o
LIB_SRCS = $(SRC)/mystrfunctions.c $(SRC)/myfilefunctions.c
LIB_OBJS = $(OBJ)/mystrfunctions.o $(OBJ)/myfilefunctions.o
STATIC_LIB = $(LIB)/libmyutils.a
SHARED_LIB = $(LIB)/libmyutils.so
STATIC_TARGET = $(BIN)/client_static
DYNAMIC_TARGET = $(BIN)/client_dynamic

# Install directories
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man3

# Default target: build both
all: $(STATIC_TARGET) $(DYNAMIC_TARGET)

# ---- Static build ----
$(STATIC_TARGET): $(MAIN_OBJ) $(STATIC_LIB) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(STATIC_LIB)

$(STATIC_LIB): $(LIB_OBJS) | $(LIB)
	ar rcs $@ $(LIB_OBJS)

# ---- Dynamic build ----
$(DYNAMIC_TARGET): $(MAIN_OBJ) $(SHARED_LIB) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(LDFLAGS) $(LDLIBS)

$(SHARED_LIB): $(LIB_OBJS) | $(LIB)
	$(CC) -shared -o $@ $(LIB_OBJS)

# ---- Compilation rules ----
$(OBJ)/main.o: $(MAIN_SRC) | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# ---- Directories ----
$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

$(LIB):
	mkdir -p $(LIB)

# ---- Install ----
install: $(DYNAMIC_TARGET)
	install -d $(BINDIR)
	install -m 755 $(DYNAMIC_TARGET) $(BINDIR)/client
	install -d $(MANDIR)
	install -m 644 $(MAN)/* $(MANDIR)

# ---- Uninstall ----
uninstall:
	rm -f $(BINDIR)/client
	for f in $(MAN)/*; do \
		rm -f $(MANDIR)/$$(basename $$f); \
	done

# ---- Clean ----
clean:
	rm -rf $(OBJ)/*.o $(STATIC_TARGET) $(DYNAMIC_TARGET) $(STATIC_LIB) $(SHARED_LIB)

