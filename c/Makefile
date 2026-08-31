CC = gcc
CFLAGS = -Wall
TARGET = test
SRCS = linked_list.c main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f ($TARGET)