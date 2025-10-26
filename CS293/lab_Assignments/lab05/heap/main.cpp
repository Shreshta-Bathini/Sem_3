#include <iostream>
#include "heap.h"

// Load input from stdin
void load_input(Heap& h) 
{
	unsigned n;
    	std::cin >> n;
    	for (unsigned i = 0; i < n; i++) 
    	{
    		int a;
        	std::cin >> a;
        	h.append(a);
    	}
}


// Run heap operations and print output in required format
void drive_heap(Heap& heap) 
{
    	// Build max-heap
    	heap.buildHeap();
    
    	// Line 1: elements in max-heap format
    	heap.print();
    	cout<<endl;
    	
    	int heapify_swap = heap.swap_count;
    	
    	// Reset swap count before sorting
    	heap.swap_count = 0;
    	
    	// Heap sort
    	heap.heapSort();
    
    	// Line 2: sorted elements
    	heap.print();
    	cout<<endl;
    	
    	// Line 3: number of swaps for heapify
    	std::cout << heapify_swap << "\n";

	int sort_swap = heap.swap_count;
    
    	// Line 4: number of swaps for sort
    	std::cout << sort_swap;
    	
    	std::cout<<endl;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    	Heap heap;
    	
    	load_input(heap);
    	
    	drive_heap(heap);
    	
    	return 0;
}

