#include <algorithm>
#include <iterator>
#include <map>

#include "cache.h"
#include "util.h"

std::map<CACHE*,std::vector<uint32_t>> nruBits;

void CACHE::initialize_replacement() {
  nruBits[this] = std::vector<uint32_t>(NUM_SET * NUM_WAY,1);
  
}

// find replacement victim
uint32_t CACHE::find_victim(uint32_t cpu, uint64_t instr_id, uint32_t set, const BLOCK* current_set, uint64_t ip, uint64_t full_addr, uint32_t type)
{
    std::vector<uint32_t> zeroes;
    for (uint32_t way = 0; way < NUM_WAY; ++way) {
        if (nruBits[set * NUM_WAY + way] == 0)
         zeroes.push_back(way);
    }

   
    if  (zeroes.empty()) {
        for (uint32_t way = 0; way < NUM_WAY; ++way) {
            nruBits[set * NUM_WAY + way] = 0;
        }

       
        uint32_t victim = rand() % NUM_WAY;
        return victim;
    }

   
    uint32_t victim = zeroes[rand() % zeroes.size()];
    return victim;
}




// called on every cache hit and cache fill
void CACHE::update_replacement_state(uint32_t cpu, uint32_t set, uint32_t way, uint64_t full_addr, uint64_t ip, uint64_t victim_addr, uint32_t type,
                                     uint8_t hit)
{
  if (hit && type == WRITEBACK)  {
    return;
  }


nruBits[this][set * NUM_WAY+way] = 1;
    

}

void CACHE::replacement_final_stats() {}
