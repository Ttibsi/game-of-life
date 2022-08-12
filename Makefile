FILES := main.cpp
OBJDIR := build/objects
OBJECTS := main.o
SRCDIR := src
VERSION := c++17

.PHONY: all
all: build

run: build/gol
	./build/gol

build: $(OBJDIR)/$(OBJECTS)
	g++ $(OBJDIR)/$(OBJECTS) -o build/gol -v

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	g++ -c -std=$(VERSION) $^ -o $@ -Wno-deprecated -Iinclude

.PHONY: clean
clean:
	rm -rf build/*
	mkdir build/objects
