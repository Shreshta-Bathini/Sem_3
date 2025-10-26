Given are N ropes of different lengths, 
the task is to connect these ropes into one rope with minimum cost, 
such that the cost to connect two ropes is equal to the sum of their lengths.

Examples:
Input: arr[] = {4,3,6,2} , N = 4
Output: 29
Explanation:
First, connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6, and 5.
Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
Finally connect the two ropes and all ropes have connected. (Recall (2 + 3) + (4 + 5) + (6 + 9) = 29)

Input: arr[] = {1, 2, 3} , N = 3
Output: 9
Explanation:
First, connect ropes of lengths 1 and 2. Now we have two ropes of lengths 3 and 3.
Finally connect the two ropes and all ropes have connected. (Recall (1+2) + (3 + 3) = 9)

Input - Take all input from standard input (cin)
Format -
First line contains T, an INTEGER indicating number of testcases.
Within each testcase, the first line will be an INTEGER N indicating number of ropes.
The following N lines within each testcase will be the INTEGER length of the N ropes.

Output: All output to standard output (cout)
Format -
Minimum cost, one INTEGER per line corresponding to each testcase. 

See sample inputs and outputs. Consider input 1. The first line is 2 indicating 2 testcases in the input.
The next line is 4 and thus the next 4 inputs {4,3,6,2} form testcase 1.
The next line is 3 and thus the next 3 inputs {1,2,3} form testcase 2.

Hence, the output has 29 on the first line and 9 on the second line (recall the explanation above)

Constraints - 
1 <= T <= 10
1 <= length of the array <= 100000
1 <= A[i] <= 1000
(ALL VALUES ARE INTEGERS)


Only modify:
ropes.cpp
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

