# directory paths
P1_SRC = problem1/src
P1_INCLUDE = problem1/include
P2_SRC = problem2/src
P2_INCLUDE = problem2/include
BUILD 	 = build
OBJ_PATH = $(BUILD)/obj

CC		= g++
CFLAGS	= -Wall -I $(P1_INCLUDE) -std=c++11
LIBRARY	= -lpthread

all: problem1

# Used to create our build/obj directory if it doesn't exist
$(OBJ_PATH)/.placeholder:
	mkdir -vp $(OBJ_PATH)
	touch $(OBJ_PATH)/.placeholder

# Generate object files for problem 1 cpp files
%.o: $(P1_SRC)/%.cpp $(OBJ_PATH)/.placeholder
	$(CC) $(CFLAGS) -c $(<) -o $(OBJ_PATH)/$@

problem1: main.o primecounter.o
	$(CC) $(LIBRARY) -o $(BUILD)/$@ $(OBJ_PATH)/main.o $(OBJ_PATH)/primecounter.o
	@echo Built problem 1, binary placed into $(BUILD)/

