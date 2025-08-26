#include "alloc.h"

void alloc_measure( unsigned VSIZE_RANGE, unsigned REPEAT, std::map<unsigned,float>& m ) {
  ClockCounter time;
  time.start();
 
  m[1] += time.stop();
}
