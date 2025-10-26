// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE  
// ************************************************************

#ifndef REVERSE_LINKED_LIST_H
#define REVERSE_LINKED_LIST_H

struct ListNode
{
    const int data;
    ListNode* next;

    explicit ListNode(int value) : data(value), next(nullptr) {}

    ListNode(int value, ListNode* ptr) : data(value), next(ptr) {}
};


class LinkedList
{
public:
    ~LinkedList();
    void push_back(int value);
    void reverse();
    void print() const;
    void clear();

private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
};

#endif
