#include "common.h"


int BinarySearch ( int * S , int n , int e ) {
  int iteration_count = 0;
  // Implement binary search here
  // instead of returning position return the number
  // of executed iterations of binary search.
  int left = 0;
  int right = n;
  int mid = (left+right)/2;
  while (left<right) {
    
    if(S[mid]==e)
    return iteration_count;
    else if (S[mid]>e) {
      left=mid+1;
    }
    else
    right=mid-1;
    mid=(left+right)/2;
     iteration_count++;
  }
  return iteration_count+1;

}

double drive_binary_search(unsigned size) {
  // Initialize an array with distinct elements

  // search all elements stored in S and computee
  // the average number of iterations in binary search
    int S[size];
    for (unsigned i=0; i<size; i++) {
      S[i]=size-i;
    }
    
    int sum = 0;
    for (unsigned i=0; i<size; i++) {
      sum+=BinarySearch(S,size,S[i]);
    }
   double result = (float(sum)/float(size));
  return result; // Dummy return
}


