#include <iostream>
#include <vector>
#include <fstream>

#include "linked-list.h"

// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE
// ************************************************************

int main(int argc, char* argv[]) {
    // Redirect input from file if provided
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    int n;
    std::cin >> n;
    LinkedList myList;

    // Handle empty list case
    if (n == 0)
    {
        std::cout << "Original: ";
        myList.print();
        myList.reverse();
        std::cout << "Reversed: ";
        myList.print();
        return 0;
    }
    
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        myList.push_back(value);
    }
    
    // std::cout << "Original: ";
    // myList.print();
    
    // Reverse the list
    myList.reverse();
    std::cout << "Reversed: ";
    myList.print();

    return 0;
}
