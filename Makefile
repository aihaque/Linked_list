## This is a simple Makefile 

# Define what compiler to use and the flags.
CC=cc
CXX=CC
CCFLAGS= -g -std=c99 -Wall -Werror

#all: test_list
all: hw1_solution 

# Compile all .c files into .o files
# % matches all (like * in a command)
# $< is the source file (.c file)
%.o : %.c
	$(CC) -c $(CCFLAGS) $<


test_list: hw1_solution.o test_list.o
	$(CC) -o test_list hw1_solution.o test_list.o
	

###################################
# BEGIN SOLUTION
hw1_solution: hw1_solution.o test_list.o
	$(CC) -o hw1 hw1_solution.o test_list.o

test_list: test_list
	@echo ""
	@echo "***** NOW TESTING YOUR CODE (not compiling any more) *****"
	@echo ""
	./hw1
# END SOLUTION
###################################


clean:
	rm -f core *.o hw1 test_list

