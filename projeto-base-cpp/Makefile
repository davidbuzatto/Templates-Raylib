# make build script.
#
# usage:
#    make: clean, compile and run
#    make clean: clean compiled file
#    make cleanAndCompile: clean compiled file and compile the project
#    make compile: compile the project
#    make compileAndRun: compile the project and run the compiled file
#    make run: run the compiled file
#
# author: Prof. Dr. David Buzatto

currentFolderName := $(lastword $(notdir $(shell pwd)))
compiledFile := $(currentFolderName).exe
CXXFLAGS := -O1 -Wall -Wextra -Wno-unused-parameter -pedantic-errors -std=c++23 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

all: clean compile run

clean:
	rm -f $(compiledFile)

compile:
	g++ *.cpp -o $(compiledFile) $(CXXFLAGS)

run:
	./$(compiledFile)

cleanAndCompile: clean compile
compileAndRun: compile run