FILES := test.cpp
OBJDIR := build/objects
OBJECTS := main.o
SRCDIR := src
VERSION := c++17

#https://www.glfw.org/docs/3.3/build_guide.html

.PHONY: all
all: build

run: build/gol
	./build/gol

build: $(OBJDIR)/$(OBJECTS)
	g++ $(OBJDIR)/$(OBJECTS) -o build/gol -Iinclude -Llib -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	g++ -c -std=$(VERSION) $^ -o $@ -Wno-deprecated

.PHONY: clean
clean:
	rm -rf build/*
	mkdir build/objects
