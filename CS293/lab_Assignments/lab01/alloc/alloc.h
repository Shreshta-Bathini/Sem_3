// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE
// ************************************************************
#include "common.h"
#include "rdtsc.h"

void alloc_measure( unsigned vsize_limit,       // Maximum length of arrays to be tested
                    unsigned repeat,            // How many times repeat the experiment?
                    std::map<unsigned,float>& m // Result of the experiment:
                                                // m[i] = average number of clock cycles to insert in a vector
                    );
