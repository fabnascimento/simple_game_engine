###################################
# Declare some Makefile variables
###################################
CC = g++
LANG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = -I"./libs/"
SRC_FILES = ./src/*.cpp ./src/**/*.cpp
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -llua5.3
OBJ_NAME = Game

###################################
# Make file rules
###################################

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	make build && ./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)
