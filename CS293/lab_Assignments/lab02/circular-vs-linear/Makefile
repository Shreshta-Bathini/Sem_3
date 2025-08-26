SHELL := /bin/bash

# Compiler
CXX := g++

# Default flags
BASE_FLAGS := -g -Wall -Wextra -Wno-sign-compare
CXXFLAGS := $(BASE_FLAGS) -std=c++20

# Source files
COMMON_SRC = main.cpp queue.h
LINEAR_SRC = linearQueue.cpp
CIRCULAR_SRC = circularQueue.cpp

# Executables
LINEAR_EXEC = linear
CIRCULAR_EXEC = circular

# Output data files
LINEAR_DATA = linear.data
CIRCULAR_DATA = circular.data

# Python plot script
PLOT_SCRIPT = plot.py


all: build runtests plot

build: linear circular

linear: $(COMMON_SRC) $(LINEAR_SRC)
	$(CXX) $(CXXFLAGS) -DLINEAR -o $(LINEAR_EXEC) main.cpp $(LINEAR_SRC)

circular: $(COMMON_SRC) $(CIRCULAR_SRC)
	$(CXX) $(CXXFLAGS) -DCIRCULAR -o $(CIRCULAR_EXEC) main.cpp $(CIRCULAR_SRC)

runtests: linear circular
	./$(LINEAR_EXEC) < ./tests/test1/input.txt > $(LINEAR_DATA)
	./$(CIRCULAR_EXEC) < ./tests/test1/input.txt > $(CIRCULAR_DATA)

plot:
	python3 $(PLOT_SCRIPT)

clean:
	rm -f $(LINEAR_EXEC) $(CIRCULAR_EXEC)
	rm -f $(LINEAR_DATA) $(CIRCULAR_DATA)
	rm -f plot.png
	rm -f *.o *~

.PHONY: all runtests plot clean
