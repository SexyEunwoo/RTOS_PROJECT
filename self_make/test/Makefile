CC = gcc

TARGET = main
CFLAGS = -o

INC_DIRS = -I include

C_SRCS = $(notdir $(wildcard *.c))
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

.PHONY: all clean

all: $(TARGET)

clean:
	rm -rf build

$(TARGET): $(C_OBJS)
	$(CC) $(INC_DIRS) $(CFLAGS) $@ $<

build/%.o: %.c 
	mkdir -p $(shell dirname $@)
	$(CC) $(INC_DIRS) -c -o $@ $<


