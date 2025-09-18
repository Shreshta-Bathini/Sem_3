#include "linked-list.h"

void LinkedList::reverse()
{
  // TODO: Implement the linked list reversal function
  // Don't forget to set tail ptr correctly as well !

  // DO NOT ALLOCATE ANY MEMORY
  
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next; // Store next node
        curr->next = prev;               // Reverse current node's pointer
        prev = curr;                    // Move prev forward
        curr = nextTemp;                // Move curr forward
    }
    head = prev;


 tail=nullptr;
}
