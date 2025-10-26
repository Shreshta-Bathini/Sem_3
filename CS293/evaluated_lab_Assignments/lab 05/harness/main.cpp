#include <iostream>
#include <vector>
#include "isHeap.h"
#include <chrono>

using namespace std;


int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    bool result;
    long int total = 0;
    for( int i = 0; i < 10; i++) {
      auto start = std::chrono::system_clock::now();
      result = isMaxHeap(arr);
      auto end = std::chrono::system_clock::now();
      auto elapsed = end - start;
      total += elapsed.count();
    }
    // cout << (result ? "YES" : "NO") << '\n';
    cout << "Result:" << (result ? 1 : 0) << '\n';
    cout << "Time:" << total << '\n';

    return 0;
}
