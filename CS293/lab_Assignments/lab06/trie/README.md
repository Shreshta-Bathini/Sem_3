# TRIE

In this part of the lab, you will be implementing the prefix trie as discussed in class. We will also be using trie to implement an autocomplete feature.

Auto-complete is used to complete the prefix of a word into a complete word. For instance, suppose our prefix is `ca'. One possible autocomplete is `cat'. There can be multiple possible auto-completions possible, in which case, you must print all of them. For instance, auto-complete for a null string is the entire dictionary. In this part of the lab, you will insert some words into a trie, which will be our set of possible words and will implement auto-complete on it.

Note that we will be using ONLY LOWERCASE characters in this part of the lab.

Your goal is to implement all the functions in trie.cpp. 
Do NOT modify the header file (trie.h)

Begin by completing the insert, search, isLastNode and getNode functions. These will form a basic implementation of a Trie. Next, implement the auto-completion functions.


# Input & Output

Input and Output will be handled by main.cpp. You can read the main.cpp to see how it calls the functions in the trie.cpp

Input Format:
First line: mode (contains 0 for implementation test or 1 for auto-complete test)
Second line: contains integer n
Next n lines: word to be inserted

Line n+3 : contains integer m
next m lines: word/prefix for query


Output Format:

If mode == 0:
line will have either "word-Yes" or "word-No" if word is in the trie or not respectively.

If mode == 1:
for a prefix, if the prefix is present it should print all possible words in dictionary order.
otherwise it will print "No word found with this prefix".

Check the tests folder for examples.

# Files to Modify (DO NOT CHANGE ANYTHING ELSE!!!!)
1. trie.cpp

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

