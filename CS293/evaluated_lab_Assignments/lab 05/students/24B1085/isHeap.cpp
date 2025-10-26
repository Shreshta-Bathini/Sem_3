#include "isHeap.h"


// TODO : Implement the function isMaxHeap

bool isMaxHeap(const std::vector<int>& data)
{
  
  // dummy output
    for (auto i =1; i<data.size(); i=i+2) {
      if (data[(i-1)/2]<data[i])
        return false;
    }
  
  return true;
}
