# Problem: circular-vs-linear

You have learnt about queues in CS 213.  A queue stores an ordered sequence of elements, and allows
two operations: insert (at tail of queue) and delete (from head of queue).

In this lab, we will implement a queue of a generic type using an array in two different ways.

In the first implementation, called linearQueue, consecutive elements in the queue are stored at
array locations with consecutive indices.  Thus, the first element in linearQueue must always be at
the array location with the smallest index (need not be 0) compared to other elements in linearQueue.
As an example, if linearQueue is implemented using an array A of size 10, and if there are 3
elements in the queue, the consecutive elements could be at locations A[3], A[4], A[5].

In the second implementation, called circularQueue, consecutive elements in the queue are stored at
array locations that are consecutive *modulo the array size*.  Thus, the first element in circularQueue
may not always be at the array location with the smallest index compared to other elements in
circularQueue.
As an example, if circularQueue is implemented using an array A of size 10, and if there are 3
elements in the queue, the consecutive elements could be at locations A[9], A[0], A[1].

When the number of elements in the queue becomes larger than the array size, you have to grow the
array size linearly, i.e. by a fixed increment.  You must not grow the array size under any other
condition.  If needed, you can re-arrange the list elements in your array to ensure that you
don't grow the array size unless the queue contains more elements than the array size.  Note that this
will incur additional time/space overhead.  So think carefully about how you would like to implement this.

Finally, we will compare the overall run-time for both the above implementations for a series of
inserts and deletes from the implemented queues.

Comparison graph: x-axis is number of operations (insert/delete), y-axis run-time;
Expect to see different graphs depending on the sequence of inserts and deletes.

Make sure to document your code properly using suitable comments.

Since in this exercise we generate two binaries, you may need to modify the binary
name in vscode config files as discussed below.

# Your Task

queue.h contains the declaration of a template class DynamicQueue.
You are required to provide implementations of the member functions for linearQueue and 
circularQueue in separate files named linearQueue.cpp and circularQueue.cpp.  

Your code must compile using the provided make file.  We may change the way the function main in main.cpp
inserts and deletes elements. main.cpp is provided to help you run your tests.  

Use make to run your solution.
Check for plot.png to see the plot generated

While testing, you can change the constant values given in queue.h if you want.

# Input/Output

The provided `main.cpp` (do **not** edit) does the following:
**Input** (stdin):
  1. An integer `n` (the number of nodes, `n ≥ 0`).
  2. `n` newline-separated integers.

**Output** (stdout):
Rows of the following pairs
  <no of operations> <time>

# Files to Edit [Do not edit any other files]

linearQueue.cpp and circularQueue.cpp



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

