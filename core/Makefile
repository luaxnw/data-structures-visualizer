CC = gcc
CFLAGS = -Wall
TARGET = test/test
SRCS = src/linked_list.c test/main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f ($TARGET)