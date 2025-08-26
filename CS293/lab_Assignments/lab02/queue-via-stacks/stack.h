#include <cstdlib>
#include <cstddef>
#pragma once

/*
 * You must NOT add ANY other includes than this.
 * The purpose of this file is to implement the functioning of a stack in C++.
 * Implement all the method functions in this file, your way.
 * Ensure that ALL of them are on average constant time. Amortized O(1) is OK.
 * You must NOT change the method signature of any of the methods.
 * You may add any additional methods or data members as you need.
 * Those methods and data members should be protected.
 */

template <typename T>
class Stack {
  T* stack;
  size_t size;
  size_t capacity;
  size_t total_operations = 0;
  // DO NOT CHANGE THE METHOD SIGNATURES BELOW
public:
  Stack();
  ~Stack();
  void push(T value);
  T pop();
  T peek();
  bool isEmpty();
  size_t getSize();
  size_t get_total_operations() { return total_operations;};
};

// ENTER YOUR IMPLEMENTATIONS OF METHODS BELOW

template <typename T>
Stack<T>::Stack() {
    stack = NULL;
    size = 0;
    capacity = 0;
}

template <typename T>
Stack<T>::~Stack() {
    free(stack);
}

template <typename T>
void Stack<T>::push(T value) {
  total_operations ++;
    if (size == capacity) {
        if (capacity == 0) {
            capacity = 1;
        } else {
            capacity *= 2;
        }
        stack = (int*)realloc(stack, capacity * sizeof(T));
    }
    stack[size++] = value;
}

template <typename T>
T Stack<T>::pop() {
    total_operations ++;
    if (size == 0) {
        throw "Empty Stack Pop Error";
    }
    if (size <= capacity / 4) {
        capacity /= 2;
        stack = (int*)realloc(stack, capacity * sizeof(T));
    }
    return stack[--size];
}

template <typename T>
T Stack<T>::peek() {
    if (size == 0) {
        throw "Empty Stack Peek Error";
    }
    return stack[size - 1];
}

template <typename T>
bool Stack<T>::isEmpty() {
    return size == 0;
}

template <typename T>
size_t Stack<T>::getSize() {
    return size;
}
