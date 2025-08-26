# Problem: avg-binary

Consider the binary search algorithm presented in class. We are interested in determining the average execution time of binary search. To accomplish this, we will conduct an experiment.

Suppose we have an array of some size that contains distinct elements arranged in non-increasing order. We have already analyzed the running time when the element being searched for is not present in the array. Now, let's assume we are searching only for elements that are guaranteed to exist in the array.

Our goal is to experimentally calculate the average number of iterations required to search for all elements in the array.

# Your Task
In avg-binary.cpp:
- Implement BinarySearch that can handle a non-increasing array.
- Implement drive_binary_search to run BinarySearch and compute the average number of iterations.

# Input/Output

Input (stdin): A non-negative number.
Output (stdout): Average number of iterations.

# Files to Edit [Do not edit any other files]

avg-binary.cpp

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


# General Instructions

- Read all .h and .cpp files before starting.
- Do not include any additional header files.
- Do not modify files other than the specified files. Any other changes 
  will not be considered during evaluation.
- You are expected to submit an efficient implementation. Inefficient 
  solutions will lose marks.

