#include "alloc.h"

void alloc_measure( unsigned VSIZE_RANGE, unsigned REPEAT, std::map<unsigned,float>& m ) {
  REPEAT = (int)sqrt(REPEAT);

  for( unsigned size = 1; size < VSIZE_RANGE; size++ ) {
      m[size] = 0.0;
  }

  ClockCounter time;
  for( unsigned l = 1; l < REPEAT; l++ ) {

    // SIZE RANGE
    for( unsigned size = 1; size < VSIZE_RANGE; size++ ) {
      time.start();

      for( unsigned r = 0; r < REPEAT; r++ ) {
        std::vector<int> s;
        for(int i=size; i>=1; i--)
          s.push_back(i);
      }

      // Save runtime
      m[size] += (time.stop()*1.0)/(REPEAT*size);

    }
  }

  for(unsigned s = 1; s < VSIZE_RANGE; s++)
    m[s] = m[s]/REPEAT;
}

