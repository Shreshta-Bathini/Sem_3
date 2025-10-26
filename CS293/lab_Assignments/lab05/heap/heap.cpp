

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION
*/


#include "heap.h"


// gives us the index of the parent for the element at index 'i'
int Heap::parent(int i) 
{
	return (i-1)/2; // dummy return
}


// gives us the index of the left child for the element at index 'i'
int Heap::left(int i) 
{
	return (2*i)+1; // dummy return
}


// gives us the index of the right child for the element at index 'i'
int Heap::right(int i) 
{
	return (2*i)+2; //dummy
}


// gives us the maximum element in the heap
int Heap::max() 
{
	return store[0]; //dummy
}


//swaps the elements at indices 'i' and 'j' in the store array
// Do not forget to increment the swap_count
void Heap::swap(int i, int j) 
{
auto temp = store[i];
store[i]=store[j];
store[j]=temp;
swap_count++;
}


// inserts elements into the store array
// can use the helper function append in heap.h
void Heap::insert(int v) 
{
	int i = store.size();
	append(v);
	
	while ((store[parent(i)] < store[i]) && i>0) {
		Heap::swap(parent(i), i);
		i=parent(i);
	}
}

// makes the subtree rooted at index 'i' follow the Max Heap property
// HINT: calls the swap and recusively goes down the subtree
void Heap::heapify(int i) 
{
	if ( i>=size())
    return;
	int l_i=i;
	if (store[left(i)]<store[right(i)] && store[i]<store[right(i)])
	l_i = right(i);
	else if (store[right(i)]<store[left(i)] && store[i]<store[left(i)])
	l_i = left(i);
	if (l_i == i) return;
	Heap::swap(l_i, i);
	heapify(l_i);
}

// deletes the maximum element and makes the remaining tree follow the max heap property
// HINT: calls the heapify
void Heap::deleteMax() 
{
	Heap::swap(0,store.size()-1);
	removeLast();
	heapify(0);
}


// rearranges the array such that it follows the max heap property
// HINT: calls the heapify
// HINT: for efiicient building follow a bottom-up approach
void Heap::buildHeap() 
{
	for (int i = store.size()-1; i>-1; i--) {
		heapify(i);
	}
}


// used to arrange the elements in descending order
// The sorted elemendts must be stored in the 'store' array
// Can use a temporary vector to sort
// HINT: Since you are using a temporary vector to sort, make sure to apply the heapify logic on that temporary vector
// and also increment the swap count whenever you perform a swap
void Heap::heapSort() 
{
    // Make a temporary copy of the current store
    vector<int> temp = store;
    int n = temp.size();

    // Helper lambda for heapify on the temp vector
    auto heapifyTemp = [&](auto&& self, int n, int i) -> void {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < n && temp[l] > temp[largest])
            largest = l;

        if (r < n && temp[r] > temp[largest])
            largest = r;

        if (largest != i) {
            std::swap(temp[i], temp[largest]);
            swap_count++; // count swaps
            self(self, n, largest);
        }
    };

    // Step 1: Build max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyTemp(heapifyTemp, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        std::swap(temp[0], temp[i]);
        swap_count++; // count swaps
        heapifyTemp(heapifyTemp, i, 0);
    }

    // Step 3: Now temp[] is in ascending order
    // Copy it in reverse to store[] for descending order
    for (int i = 0; i < n; i++) {
        store[i] = temp[n - 1 - i];
    }
}



