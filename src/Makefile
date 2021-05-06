CC = gcc
INCDIR = ../inc
CCFLAGS = -W -Wall
SRC = main.c CrudOperations.c manager.c
OBJ = $(SRC:.c=.o)
TARGET = calGPA

$(TARGET) : $(OBJ)
	$(CC) $^ -o $@

$(OBJ) : $(SRC)
	$(CC) -c $(CCFLAGS) $^ -I$(INCDIR)

clean :
	rm -rf *.o $(TARGET)