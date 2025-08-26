// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE
// ************************************************************

#include "queue-via-stack.h"

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <chrono>
#include <random>
#include <fstream>

bool checkTestcaseQueue(std::vector<std::pair<int, std::string>> testcase) {
    double duration = 0.0;
    std::queue<int> stl_queue;
    auto start = std::chrono::high_resolution_clock::now();
    class Queue<int> my_queue;
    auto stop = std::chrono::high_resolution_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>(
            stop - start).count();

    size_t queue_actions = 0;
    for (std::pair<int, std::string> call : testcase) 
    {
        if (call.second == "ENQUEUE") {
          queue_actions++;
            start = std::chrono::high_resolution_clock::now();
            my_queue.enqueue(call.first);
            stop = std::chrono::high_resolution_clock::now();
            duration += std::chrono::duration_cast<std::chrono::nanoseconds>(
                    stop - start).count();
            stl_queue.push(call.first);
        } 
        else if (call.second == "DEQUEUE") {
          queue_actions++;
            try {
                start = std::chrono::high_resolution_clock::now();
                int result = my_queue.dequeue();
                stop = std::chrono::high_resolution_clock::now();
                duration += std::chrono::duration_cast<std::chrono::nanoseconds>(
                        stop - start).count();

                int expected_value = stl_queue.front();
                stl_queue.pop();

                if (result != expected_value) {
                    std::cout << "Testcase failed: Expected " << expected_value << 
                        " but got " << result << std::endl;
                    return false;
                }
            } 
            catch (char const* &e) {
                std::cout << "Testcase failed: Expected " << stl_queue.front() << 
                    " but got exception" <<  std::endl;
                return false;
            }
        }
        else if (call.second == "PEEK") {
            try {
                start = std::chrono::high_resolution_clock::now();
                int result = my_queue.peek();
                stop = std::chrono::high_resolution_clock::now();
                duration += std::chrono::duration_cast<std::chrono::nanoseconds>(
                        stop - start).count();
                int expected_value = stl_queue.front();

                if (result != expected_value) {
                    std::cout << "Testcase failed: Expected " << expected_value << 
                        " but got " << result << std::endl;
                    return false;
                }
            } 
            catch (char const* &e) {
                std::cout << "Testcase failed: Expected " << stl_queue.front() << 
                    " but got exception" << std::endl;
                return false;
            }
        } 
        else if (call.second == "ISEMPTY") {
            start = std::chrono::high_resolution_clock::now();
            bool result = my_queue.isEmpty();
            stop = std::chrono::high_resolution_clock::now();
            duration += std::chrono::duration_cast<std::chrono::nanoseconds>(
                    stop - start).count();
            if (result != stl_queue.empty()) {
                std::cout << "Testcase failed: Expected " << stl_queue.empty() << 
                    " but got " << result << std::endl;
                return false;
            }
        } 
        else if (call.second == "GETSIZE") {
            start = std::chrono::high_resolution_clock::now();
            size_t result = my_queue.getSize();
            stop = std::chrono::high_resolution_clock::now();
            duration += std::chrono::duration_cast<std::chrono::nanoseconds>(
                    stop - start).count();
            if (result != stl_queue.size()) {
                std::cout << "Testcase failed: Expected " << stl_queue.size() << 
                    " but got " << result << std::endl;
                return false;
            }
        }
    }
    auto total_operations = my_queue.first_stack.get_total_operations()+my_queue.second_stack.get_total_operations();

    // std::cout << "Size: " << testcase.size() << std::endl;
    // std::cout << "Per action runtime:" << duration / testcase.size() << std::endl;
    std::cout << "Number of stack actions:" << total_operations << std::endl;

    return true;
}

std::vector<std::pair<int, std::string>> readTestcaseFromFile(const std::string& filename) 
{
    std::ifstream infile(filename);
    std::vector<std::pair<int, std::string>> testcase;
    if (!infile.is_open()) 
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return testcase;
    }

    int value;
    std::string operation;
    std::string line;
    while (std::getline(infile, line)) 
    {
        size_t comma_pos = line.find(',');
        if (comma_pos == std::string::npos) continue;

        value = std::stoi(line.substr(0, comma_pos));
        operation = line.substr(comma_pos + 1);
        testcase.push_back({value, operation});
    }

    infile.close();
    return testcase;
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

    std::vector<std::pair<int, std::string>> testcase;
    for( auto i = 0; i < n; i++ ) {
      int v;std::cin >> v;
      char comma;std::cin >> comma;
      std::string s;std::cin >> s;
      testcase.push_back({v,s});
    }

    checkTestcaseQueue(testcase);

    // int num_correct = 0;
    // // Run predefined stack test
    // std::vector<std::pair<int, std::string>> TESTCASE = {
    //     {1, "PUSH"}, {2, "PUSH"}, {3, "PUSH"}, {0, "PEEK"}, {0, "POP"},
    //     {0, "PEEK"}, {4, "PUSH"}, {5, "PUSH"}, {6, "PUSH"}, {1, "POP"},
    //     {2, "POP"}, {3, "POP"}, {4, "POP"}, {5, "POP"}, {0, "ISEMPTY"}
    // };
    
    // num_correct += checkTestcaseStack(TESTCASE, 1);

    // // Stack tests from file
    // for (int size : {1000, 10000, 100000}) 
    // {
    //     std::string filename = "tests/stack_test_" + std::to_string(size) + ".txt";
    //     auto testcase = readTestcaseFromFile(filename);
    //     num_correct += checkTestcaseStack(testcase, i);
    //     i++;
    // }

    // Run predefined queue test
    // std::vector<std::pair<int, std::string>> TESTCASE = {
    //     {1, "ENQUEUE"}, {2, "ENQUEUE"}, {3, "ENQUEUE"}, {0, "PEEK"},
    //     {0, "DEQUEUE"}, {0, "PEEK"}, {4, "ENQUEUE"}, {5, "ENQUEUE"},
    //     {6, "ENQUEUE"}, {1, "DEQUEUE"}, {2, "DEQUEUE"}, {3, "DEQUEUE"},
    //     {4, "DEQUEUE"}, {5, "DEQUEUE"}, {0, "ISEMPTY"}, {0, "GETSIZE"}
    // };
    // num_correct += checkTestcaseQueue(TESTCASE, 1);
    
    
    // // Queue tests from file
    // for (int size : {1000, 10000, 100000}) 
    // {
    //     std::string filename = "tests/queue_test_" + std::to_string(size) + ".txt";
    //     auto testcase = readTestcaseFromFile(filename);
    //     num_correct += checkTestcaseQueue(testcase);
    // }

    // std::cout << "\nRESULTS: " << num_correct << " / 8" << std::endl;
    return 0;
}

