// #include <cstdlib>
// #include <cstddef>
#include "stack.h"
#pragma once


template <typename T>
class Queue {
public:
    class Stack<T> first_stack;
    class Stack<T> second_stack;
    Queue();
    ~Queue();
    void enqueue(T value);
    T dequeue();
    T peek();
    bool isEmpty();
    size_t getSize();
};

