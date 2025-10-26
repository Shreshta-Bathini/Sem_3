#include "crc.h"
using namespace std;

/**
 * Perform modulo-2 division of `data` by `generator` and return the remainder.
 * `data` is expected to be (message + k zeros) where k = generator.size() - 1
 */
string modulo2Division(string data, const string &generator) {
    // You can assume data.size() >= generator.size()
    // TODO
    
    for (long unsigned int i=0; i<data.size()-generator.size(); i++) {
        if (data[i]!='0') {
            for (long unsigned int j =0; j<generator.size(); j++) {
                data[i+j]=(data[i+j] - '0' ) ^ (generator[j]-'0');
            }
            
        }
    }
    string rem;
    rem = data.substr(data.size()-generator.size()+1);
    return rem;
}

/**
 * Compute the CRC codeword by appending remainder to `message`.
 */
string generateCRC(const string &message, const string &generator) {
    // TODO:
    // 1) Append generator.size() - 1 zeros to message
    // 2) find remainder using above function
    // 3) return message + rem
    string data = message;
    for (long unsigned int i = 0; i<generator.size()-2; i++ )
        data += "0";
    string rem = modulo2Division(data,generator);     
    return message+rem;
}

/**
 * Verify if `received` is error-free under given `generator`.
 * Returns true if remainder is all zeros, false otherwise.
 */
bool checkCRC(const string &received, const string &generator) {
    // TODO:
    // Compute remainder of `received` by `generator`.
    // If remainder is all '0', return true, else false.
    string codeword = received;
    for (long unsigned int i=0; i<received.size()-generator.size(); i++) {
        
        if (codeword[i]!='0') {
            for (long unsigned int j =0; j<generator.size(); j++) {
                codeword[i+j]=(codeword[i+j] - '0' ) ^ (generator[j]-'0');
            }
            
        }
    }
    string rem;
    rem = received.substr(codeword.size()-generator.size()-1);
        for (long unsigned int c : rem) {
            if (c=='1')
            return false;
        } 

    return true;
}
