SRCDIR := \src
BINDIR := \bin

SOURCES := $(shell find $(SRCDIR) -name "*.cpp")
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

CC 			:= g++
FLAGS		:= -g -std=c++11 -Wall -pedantic -Werror -Wc++11-extensions
CC-FLAGS	:= $(CC) $(FLAGS)

ALLFILES 	:= $(SOURCES)
LIBS 		:= CoreFoundation

.PHONY: all

all: clean sts2msw
	./out

sts2msw: $(OBJECTS)
	$(CC-FLAGS) $^ -o out

clean:
	rm -rf $(OBJECTS) out
	clear