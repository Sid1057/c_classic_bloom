CC=gcc 
CAPPFLAGS= -std=c11  -o0 -Wall -Wextra -pedantic
CCFLAGS= -c -std=c11 -o0 -Wall -Wextra -pedantic

PROJECTDIR= .

TEST=./test
OBJ=./obj
BIN=./bin


test: bloom_test.c $(OBJ)/bloom.o $(OBJ)/bit_array.o 
	$(CC) $(CAPPFLAGS) $^ -o $(BIN)/simple_test
	$(BIN)/simple_test

$(OBJ)/main.o: main.c $(OBJ)/bit_array.o $(OBJ)/set.o $(OBJ)/bloom.o skip_list.h
	$(CC) $(CCFLAGS) $< -o $@

$(OBJ)/set.o: set.c $(OBJ)/bloom.o set.h skip_list.h  
	$(CC) $(CCFLAGS) $< -o $@

$(OBJ)/bloom.o: bloom.c bloom.h bloom_templates.c bloom_templates.h bloom_macros.h $(OBJ)/bit_array.o
	$(CC) $(CCFLAGS) $< -o $@

$(OBJ)/bit_array.o: bit_array.c bit_array.h
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*
	rm $(TEST)/$(OBJ)/*.o
	rm $(TEST)/$(BIN)/*
