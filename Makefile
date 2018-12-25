CC=g++ # указываем компилятор
LDFLAGS= # флаги линковщика
CFLAGS=-c  # флаги компилятора
SOURCES= Main.cpp Contact.cpp ContactBook.cpp # список исходников
OBJECTS=$(SOURCES:.cpp=.o)
TARGET= contact # имя бинарника

all: $(TARGET)
    
$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp 
	$(CC) $(CFLAGS) $< 

include $(wildcard   *.d)

clean:
        rm *.o *.d $(TARGET)
