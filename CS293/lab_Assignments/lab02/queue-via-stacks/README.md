# Problem: queue-via-stacks

We have seen both stacks and queues as part of our course. In this problem we will try to implement a queue using stacks.


# YOUR TASK

Stack implementation is already given In stack.h

In queue.h: Implement the queue functions using two stacks. 

The purpose of this exercise is to implement the functioning of a queue in C++.
The task is to implement a Queue using stacks. This requires two stacks.
Ensure that ALL of them are on average constant time. Amortized O(1) is OK.
You must NOT change the data members or ANY of the method signatures.
NOR are you allowed to add any additional methods or data members.
You are free to use only the PUBLIC methods of the Stack class here.

On empty queue dequeue and peek should throw the following exception:
```
      throw std::invalid_argument("Empty Queue Dequeue Error"); // For Dequeue
      throw std::invalid_argument("Empty Queue Peek Error")   ; // Peek
```

You must NOT add ANY other includes than what is already here.

# INPUT/OUTPUT

You are provided with main.cpp which will take input from the tests and show the status of 
whether you have passed the tests case or not. There will be 8 total test cases.


# Files to Edit [Do not edit any other files]:

queue-via-stack.h
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

In some labs, we may multiple binaries, then you may need to modify the 
name of the binary in the following line of the "./.vscode/settings.json".

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

