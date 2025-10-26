# Makefile for heap program
SHELL := /bin/bash

# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++20 -Wno-unused-parameter -Werror

# Executable name
EXEC = heap

# Source files
SOURCES = main.cpp heap.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Test configuration
TCDIR = tests
NUM_TEST_CASES = 1   # update if you add more test folders (test1...testN)

# Default target
all: build runtests

# Build target
build: $(EXEC)

# Link executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Compile object files
%.o: %.cpp *.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run all tests
runtests: $(EXEC)
	@echo -e "Running Test Cases"
	@for i in `seq 1 $(NUM_TEST_CASES)`; do \
		echo -e "\n\033[0;36mTestcase $$i\033[0m"; \
		./$(EXEC) < $(TCDIR)/test$$i/input.txt > output.txt; \
		# only compare first 2 lines \
		head -n 2 output.txt > out_first2.txt; \
		head -n 2 $(TCDIR)/test$$i/output.txt > exp_first2.txt; \
		if diff -Bw out_first2.txt exp_first2.txt > /dev/null; then \
			echo -e "\033[0;32mPASSED\033[0m"; \
		else \
			echo -e "diff -Bw first 2 lines"; \
			diff -Bw out_first2.txt exp_first2.txt; \
			echo -e "\033[0;31mFAILED\033[0m"; \
		fi; \
		# also print swap counts for reference \
		echo "Expected swaps for buildHeap and heapSort:"; \
		sed -n '3,4p' $(TCDIR)/test$$i/output.txt; \
		echo "Actual swaps for buildHeap and heapSort:"; \
		sed -n '3,4p' output.txt; \
	done
	@rm -f output.txt out_first2.txt exp_first2.txt

# Clean target
clean:
	rm -f $(EXEC) $(OBJECTS) output.txt out_first2.txt exp_first2.txt

.PHONY: all build runtests clean

