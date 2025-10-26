#include "linked-list.h"

void LinkedList::reverse()
{
  // TODO: Implement the linked list reversal function
  // Don't forget to set tail ptr correctly as well !

  // DO NOT ALLOCATE ANY MEMORY
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (!curr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    
  }
  head = prev;

}
