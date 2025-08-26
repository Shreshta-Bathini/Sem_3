#include "dictionary.h"

// ------------------------------------------------
//  IMPORTANT
// ------------------------------------------------
// You must have written dictionary.cpp for earlier problem.
// You need to use the code here again. However, there is
// a type difference in this problem. The key is a string not array.
// Please modify your code as you need.

Dictionary::Dictionary(){
  // (ALMOST) COPY from the earlier dictionary problem
};


//Constructor for defining capacity of the hash table. In this problem this will be used.(DO NOT MODIFY !!!!!!!)
Dictionary::Dictionary(int n) {
    N = n;
    A = new Entry[N];
    for (int i = 0; i < N; i++) {
        A[i].key = "";
        A[i].value = (int)NULL;
    }
};


int Dictionary::hashValue(std::string key){
  // (ALMOST) COPY from the earlier dictionary problem
    int hashValue = 0;

    return hashValue;
}

int Dictionary::findFreeIndex(std::string key){
  // (ALMOST) COPY from the earlier dictionary problem
    return -1;
}

struct Entry* Dictionary::get(std::string key){
  // (ALMOST) COPY from the earlier dictionary problem
    return NULL;
}

bool Dictionary::put(Entry e){
  // (ALMOST) COPY from the earlier dictionary problem
  return false; // Dummy return
}

bool Dictionary::remove(std::string key){
  // (ALMOST) COPY from the earlier dictionary problem
    return false; // Dummy return
}


//Method to Dump Table (DO NOT MODIFY THIS METHOD !!!!!!)
std::vector<std::tuple<std::string,int,int>> Dictionary::dumpTable() {
    std::vector<std::tuple<std::string,int,int>> result;
    for (int i = 0; i < N; i++) {
        if (A[i].key != "" && A[i].key != "TOMBSTONE") {
            result.push_back({A[i].key, A[i].value, i});
        }
    }
    return result;
}
