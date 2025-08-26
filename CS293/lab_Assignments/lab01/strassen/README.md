# Problem: strassen

Strassen’s algorithm has a time complexity less than O(n^3). However, it does not perform well for smaller input sizes. In this lab, you will implement both Strassen’s algorithm and the naive algorithm for matrix multiplication to compare their performances.

Implement both the naive matrix multiplication and Strassen’s algorithm, and experimentally determine the value of N (matrix size) at which Strassen’s algorithm becomes faster.

Within your Strassen implementation, consider switching to the naive multiplication when N is smaller than a threshold to avoid overhead. Please also experimentally determine a good value of threshold.


Reference: [Strassen Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Strassen_algorithm)


# Your Task
In `strassen.cpp`, implement:

1. **Naive matrix multiplication** using the standard `O(N^3)` algorithm.
2. **Strassen’s algorithm** using a recursive divide-and-conquer approach.

Compare the performance of both algorithms by measuring their runtimes on randomly generated square matrices of increasing sizes (powers of 2). Identify the smallest value of `N` at which Strassen’s algorithm outperforms the naive method.

# Input/Output

Input (stdin):

None required. The code should automatically:
- Run both algorithms on matrices of sizes `N = 2, 4, 8, 16, 32, ..., 1024` (or up to a reasonable limit).
- Use randomly generated integer matrices (e.g., values in range `[-10, 10]`).

Output (stdout):

Print the runtime (in milliseconds or microseconds) of both algorithms for each tested value of `N`.


# Files to Edit [Do not edit any other files]

- `strassen.cpp`


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

