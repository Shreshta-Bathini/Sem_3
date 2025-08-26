#include "queue.h"
#include "common.h"
#ifdef LINEAR
#include "linearQueue.cpp"
#endif

#ifdef CIRCULAR
#include "circularQueue.cpp"
#endif

using namespace std;
using namespace std::chrono;

void do_insert_delete(DynamicQueue<int>&, int, long&, long&, const vector<int>&);

std::vector<int> load_test_data(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open test data file.");
    }

    std::vector<int> data;
    int value;
    while (file >> value) {
        data.push_back(value);
    }

    return data;
}

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

  try {
    srand(time(0)); // Seed random once (optional now)

    DynamicQueue<int> myQueue; // Queue of integers
    long num_ins = 0, num_del = 0;
    int total_num_ops = 10000;
    int points_to_plot = 100;

    std::vector<int> test_data;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        test_data.push_back(value);
    }

    // Load test data
    // std::vector<int> test_data = load_test_data("tests/test1.txt");

    for (int i = 0; i < points_to_plot; i++) {
      auto start = std::chrono::high_resolution_clock::now();
      do_insert_delete(myQueue, total_num_ops, num_ins, num_del, test_data);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      cout << (num_ins + num_del) << " " << duration.count() << endl;
    }

    return 0;
  }
  catch (exception const& ex) {
    cerr << "Exception " << ex.what() << endl;
    return -1;
  }
}

void do_insert_delete(DynamicQueue<int>& q, int N, long& num_ins, long& num_del, const std::vector<int>& test_data)
{
  int element;
  int thresh_for_del = 20;

  size_t test_data_index = 0;

  for (int i = 0; i < N; i++) {
    if ((i > 0) && (i % thresh_for_del == 0)) {
      // Delete element from queue
      if (q.QDelete(&element)) {
        num_del++;
      }
    }
    else {
      if (test_data_index >= test_data.size()) {
        throw std::runtime_error("Not enough test data for insertions.");
      }

      // Insert element from test data
      element = test_data[test_data_index++];
      q.QInsert(element);
      num_ins++;
    }
  }

  return;
}
