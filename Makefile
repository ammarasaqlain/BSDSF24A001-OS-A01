CC = gcc
CFLAGS = -Wall -Wextra -fPIC
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib

DYN_LIB = $(LIB_DIR)/libmyutils.so
TARGET_DYN = $(BIN_DIR)/client_dynamic

LIB_SRCS = $(SRC_DIR)/mystrfunctions.c $(SRC_DIR)/myfilefunctions.c
LIB_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_SRCS))

MAIN_SRC = $(SRC_DIR)/main.c
MAIN_OBJ = $(OBJ_DIR)/main.o

all: $(TARGET_DYN)

$(TARGET_DYN): $(MAIN_OBJ) $(DYN_LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -L$(LIB_DIR) -lmyutils -o $@

$(DYN_LIB): $(LIB_OBJS)
	$(CC) -shared -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/client* $(LIB_DIR)/*
