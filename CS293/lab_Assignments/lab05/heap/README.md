# HEAP

In this problem we will try to implement heap data structure as we learned in the class, more specifically we are implementing a Max Heap. In a Max Heap the parent is greater than or equal to its children.


# TASK

Implement the various functions of the heap that are listed in heap.cpp

You can see heap.h to see how the heap is storing the elements and other functions that are already implemented.

Your main task is to implement the functions as efficiently as possible. This is tracked through number of swaps that are done in the heapify() and heapsort().

Read the description of each function to understand what it does.

In this problem the elements are stored in a array. For a element at index i, its children will be at index 2*i and 2*i +1

# Input & Output

The input and output is handled by main.cpp. Take a look at it to understand how it is taking input and what the output means. You can find the test cases in the test sub folder for various inputs and outputs.

Input Format:
First Line: n - number of elements
next n lines: x -a number

Output Format:
First Line: 'n' elements separated by space in the Max Heap order
Second Line: 'n' elements separated by space in descending order
Third Line: number of expected swaps for build heap
Fourth Line: number of expected swaps for heapsort

You will pass the test cases if the first two lines are matching.
For the next two lines if you are getting more swaps than expected, you have a inefficient implementation.

Example:
Input:
2
1
2

Output:
2 1
2 1
1
2

# Files to Edit (DO NOT MODIFY ANYTHING ELSE)

1. heap.cpp


# Make Commands

```
make             # Build and Run Tests
make build       # Build
make runtests    # Run Tests
make clean       # Clean Temporary Files
```
Please read Makefile to understand the above commands!

# VS Code interface

You can open this folder in VS Code. The problem folder is configured 
to enable debugging.

After opening the folder, click on Run > Start Debugging or press F5.
This will run your program on input ./test/test1/input.txt.
You may place breakpoints to pause the program at any desired location.

You can modify "./.vscode/launch.json" to run any test of your choice.

In some labs, there may be multiple binaries, and you may need to modify 
the binary name in the ./.vscode/settings.json file.

```
    "problem": "<binary>",
```

# General Instructions

- Read all .h and .cpp files before starting.
- Do not include any additional header files.
- Do not modify files other than the specified files. Any other changes 
  will not be considered during evaluation.
- You are expected to submit an efficient implementation. Inefficient 
  solutions will lose marks.

