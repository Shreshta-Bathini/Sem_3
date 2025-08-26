# Dictionary

In this part, you will implement the dictionary data structure as
 you have studied in CS213.

• Implement a dictionary of strings (consider each string is
  null-terminated, of max length 32, including the null).
  Use the dictionary to map a string to an integer.  
• The hash code map should use a polynomial accumulation scheme
  (be careful of overflow)  
• The compression map should use the Fibonacci compression scheme.  
• Use a fixed-length array for the dictionary. Say 64 should be adequate.  
• To resolve hash collisions, use the simple linear probing scheme with
  appropriate NULL and TOMBSTONE markers (as described in the lecture
  slides)  


### Polynomial Accumulation

The polynomial rolling hash function is a hash function that uses only
 multiplications and additions. The following is the function:

hash(s) = s[0] + s[1]p + s[2]p^2 . . . s[n − 1]p^{n−1}


where p is some positive integer. Use p as 31 or 33.


### Fibonacci Compression

Used to map a key to an index in the hash table. We use h(k) = ⌊ m {kA} ⌋

where k is the key, A is constant between 0 and 1, and
m is the size of the hash table. In Fibonacci compression,
we use A as the conjugate of the golden ratio, or (√5−1)/2.


### Implementation

Please write all code for this code in the dictionary.cpp file using
this header file dictionary.h. Do not change the header, main or any other file.

## Running Instructions


Compile your code by running

   $make dictionary

Follow the following instructions for testing your dictionary manually.

• Run dictionary in manual(interactive) mode.

   $./dictionary 0

  The Interactive part of the Testing can take these instructions

  – QUIT: end the interactive mode and exit the program

  – INS <key> <value>: Insert the key-value pair into the Dictionary

  – DEL <key>: Delete the key from the dictionary if found

  – FIND <key>: Find and returns the key-value pair
  
  Follow the following instructions for testing your dictionary
  automatically. (These are optional to run)

• Run our test cases on your dictionary
   $make runtests

• Check distribution of buckets on random inputs.
   $make random
   --see the plot 'Hash.png' generated

• Check distribution of buckets on english words.
   $make english
   --see the plot 'Hash.png' generated

The words are from the following URL
https:github.com/dwyl/english-words/blob/master/words.txt

Please use other constants for p and A in your implmentation to see the impact on the distributions.


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

