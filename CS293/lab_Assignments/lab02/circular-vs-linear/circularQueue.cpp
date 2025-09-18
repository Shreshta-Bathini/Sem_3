#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  if (tail==head)
    return true; // dummy return
  return false;
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  if ((N+tail-head)==N-1)
    return true;
  return false; // dummy return
}

template <typename T> void DynamicQueue<T> :: grow() {
  if(isFull()) {
    unsigned int old = N;
    N = nextSize();
    T* p = new T[N]; // new array of larger size
    int i = 0, j = 0, count;
    for( i=0, j=head, count=1; count <= old; i++, count++) {
      p[i] = A[(j+i)%old]; // Copying element by element into new array
    }
    head = 0; // Setting head at 0
    tail = i; // Setting tail at N + 1
    delete[] A; // Freeing up older array
    A=p;
  } else
    return;
}


template <typename T> unsigned int DynamicQueue<T> :: size() {
  if (tail!=head)
    return (N+tail-head)%N;
  return 0; // dummy return
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if (isFull())
    grow();
  A[tail]=x;
  tail=(tail+1)%N;

}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if (isEmpty())
    return false;
  *x = A[head];
  
  
  head=(head+1)%N;
  return true; // dummy return
}
