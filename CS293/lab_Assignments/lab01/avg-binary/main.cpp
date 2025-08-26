#include<iostream>
#include<fstream>
#include "common.h"
#include "avg-binary.h"

// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE
// ************************************************************

int main(int argc, char *argv[]) {
  if (argc > 1) {
    freopen(argv[1], "r", stdin); // Redirect the standard input to a file
  }
  unsigned size;
  std::cin >> size;
  double num_avg_interations = drive_binary_search(size);
  std::cout <<std::setprecision(20)<< "Average: " << num_avg_interations << "\n";
  return 0;
}
