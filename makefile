CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = 
OBJFILES = Main.o LinkedListAPI.o
TARGET = List_App

all: $(TARGET)
	
$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

run:
	./$(TARGET)
	
valgrind:
	valgrind ./$(TARGET)
	
clean:
	rm -f $(OBJFILES) $(TARGET) *~
	rm -rf $(TARGET).dSYM