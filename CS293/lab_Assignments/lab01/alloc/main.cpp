#include<iostream>
#include<fstream>
#include "common.h"
#include "alloc.h"

// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE
// ************************************************************

int main(int argc, char *argv[]) {
  if (argc > 1) {
    freopen(argv[1], "r", stdin); // Redirect the standard input to a file
  }
  unsigned vsize_limit;
  unsigned repeat;
  std::cin >> vsize_limit;
  std::cin >> repeat;
  std::map<unsigned,float> m;
  alloc_measure( vsize_limit, repeat, m );
  for( auto pr : m ) {
    std::cout << pr.first << " " << pr.second << "\n";
  }
  return 0;
}
