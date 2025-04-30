CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = budget_tracker

# Object files
OBJ = main.o budget.o

# The rule for compiling the project
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

main.o: main.cpp budget.h
	$(CC) $(CFLAGS) -c main.cpp

budget.o: budget.cpp budget.h
	$(CC) $(CFLAGS) -c budget.cpp

# Clean up object files
clean:
	rm -f $(OBJ) $(TARGET)