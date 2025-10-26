#include <iostream>
#include "crc.h"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc > 1) {
    freopen(argv[1], "r", stdin); // Redirect the standard input to a file
  }

    string message, generator;
    cin >> message >> generator;

    string codeword = generateCRC(message, generator);
    cout << "Transmitted Codeword: " << codeword << '\n';

    string received;
    cin >> received;

    if (checkCRC(received, generator)) {
        cout << "Received message is error-free." << '\n';
    } else {
        cout << "Error detected in received message!" << '\n';
    }

    return 0;
}
