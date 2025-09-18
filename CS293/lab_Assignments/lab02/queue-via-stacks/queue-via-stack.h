// WRITE IMPLEMENTATIONS OF METHODS BELOW
#include <cstdlib>
#include <cstddef>
#include <stdexcept>
#include "queue.h"
#include "stack.h"



template <typename T>
Queue<T>::Queue() {
    
}

template <typename T>
Queue<T>::~Queue() {
    
}

template <typename T>
void Queue<T>::enqueue(T value) {
    first_stack.push(value);

    return; //dummy
}

template <typename T>
T Queue<T>::dequeue() {
    if (first_stack.isEmpty())
    throw std::invalid_argument("Empty Queue Dequeue Error");
    else {
        while (!first_stack.isEmpty()) {
            second_stack.push(first_stack.peek());
            first_stack.pop();
        }
    }
        auto front = second_stack.peek();
        second_stack.pop();
        
    return front;

     //dummy
}

template <typename T>
T Queue<T>::peek() {
if (first_stack.isEmpty()&&second_stack.isEmpty())
throw std::invalid_argument("Empty Queue Peek Error");
else if (second_stack.isEmpty())  { 
    if (second_stack.isEmpty()) {
        while (!first_stack.isEmpty()) {
            second_stack.push(first_stack.pop());
        }
    }
}//dummy
return second_stack.peek();
}

template <typename T>
bool Queue<T>::isEmpty() {
    if(first_stack.isEmpty()&&second_stack.isEmpty())
    return true; // dummy
    else 
    return false;
}

template <typename T>
size_t Queue<T>::getSize() {
    return first_stack.getSize()+second_stack.getSize(); // dummy
}
