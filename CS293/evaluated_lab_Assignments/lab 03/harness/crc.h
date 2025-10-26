#ifndef CRC_H
#define CRC_H

#include <string>
using namespace std;

string modulo2Division(string data, const string &generator);

string generateCRC(const string &message, const string &generator);

bool checkCRC(const string &received, const string &generator);

#endif
