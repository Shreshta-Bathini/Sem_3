#include "ropes.h"
#include "common.h"
int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    int T;
    std::cin >> T;
    int arr[100000];
    for (int i = 0; i < T;i++)
    {
        int size;
        std::cin >> size;
        for (int j = 0;j<size;j++) std::cin >> arr[j];
        std::cout << minCost(arr, size) << std::endl; // Write a function mincost which takes the array and size as parameters and returns the integer solution
    }
	return 0;
}
