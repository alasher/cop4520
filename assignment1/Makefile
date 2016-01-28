# directory paths
P1_SRC = problem1/src
P1_INCLUDE = problem1/include
P2_SRC = problem2/src
P2_INCLUDE = problem2/include
BUILD 	 = build
OBJ_PATH = $(BUILD)/obj

CC		= g++
CFLAGS	= -Wall -I $(P1_INCLUDE) -I $(P2_INCLUDE) -std=c++11
LIBRARY	= -lpthread

all: problem1 problem2 printer
	@echo All files built, placed into current directory

# Used to create our build/obj directory if it doesn't exist
$(OBJ_PATH)/.placeholder:
	mkdir -vp $(OBJ_PATH)
	touch $(OBJ_PATH)/.placeholder

# Generate object files for problem 1 cpp files
%.o: $(P1_SRC)/%.cpp $(OBJ_PATH)/.placeholder
	$(CC) $(CFLAGS) -c $(<) -o $(OBJ_PATH)/$@

%.o: $(P2_SRC)/%.cpp $(OBJ_PATH)/.placeholder
	$(CC) $(CFLAGS) -c $(<) -o $(OBJ_PATH)/$@

problem1: main.o primecounter.o
	$(CC) $(LIBRARY) -o $@primes $(OBJ_PATH)/main.o $(OBJ_PATH)/primecounter.o

problem2: parta partb partc partd

parta: part1.o
	$(CC) $(LIBRARY) -o problem2$@ $(OBJ_PATH)/part1.o

partb: part2.o
	$(CC) $(LIBRARY) -o problem2$@ $(OBJ_PATH)/part2.o

partc: part3.o
	$(CC) $(LIBRARY) -o problem2$@ $(OBJ_PATH)/part3.o

partd: part4.o
	$(CC) $(LIBRARY) -o problem2$@ $(OBJ_PATH)/part4.o
	
printer:
	@echo Built problem 1 - ./problem1primes
	@echo Built problem 2 - ./problem2parta
	@echo Built problem 2 - ./problem2partb
	@echo Built problem 2 - ./problem2partc
	@echo Built problem 2 - ./problem2partd

help:
	@echo Makefile options:
	@echo make: equivalent to make all
	@echo make all: make both problem 1 and 2
	@echo make problem[x]: make all executables for problem [x]
	@echo make part[c]: make individual part [c] for problem 2