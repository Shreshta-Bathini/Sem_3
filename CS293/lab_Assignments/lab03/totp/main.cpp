#include "common.h"
#include "totp.h"

// A simple function to get the current time-step
uint64_t getCurrentTimeStep() {
    // For this example, we use a fixed time step.
    // In a real application, you would calculate this:
    time_t current_time = time(nullptr);
    return current_time / 30;
    // We use an RFC test vector time step for consistency.
    return 1;
}
bool debug = false;

void test_sha1() {
    if(debug)
        std::cout << "--- Testing Part 1: SHA-1 ---" << std::endl;

    std::string msg_str = "The quick brown fox jumps over the lazy dog";
    std::vector<uint8_t> message(msg_str.begin(), msg_str.end());
    std::vector<uint8_t> expected_hash = {
        0x2f, 0xd4, 0xe1, 0xc6, 0x7a, 0x2d, 0x28, 0xfc, 0xed, 0x84,
        0x9e, 0xe1, 0xbb, 0x76, 0xe7, 0x39, 0x1b, 0x93, 0xeb, 0x12
    };
    std::vector<uint8_t> computed_hash = sha1(message);

    if(debug){
        if (computed_hash == expected_hash) {
            std::cerr << "PASSED: SHA-1 implementation is correct." << std::endl;
        } else {
            std::cerr << "FAILED: SHA-1 implementation is incorrect." << std::endl;
        }
    }
}

void test_hmac() {
    if(debug)
        std::cerr << "\n--- Testing Part 2: HMAC-SHA1 ---" << std::endl;
    std::string key_str = "Jefe";
    std::string msg_str = "what do ya want for nothing?";
    std::vector<uint8_t> key(key_str.begin(), key_str.end());
    std::vector<uint8_t> msg(msg_str.begin(), msg_str.end());
    std::vector<uint8_t> expected_hmac = {
        0xef, 0xfc, 0xdf, 0x6a, 0xe5, 0xeb, 0x2f, 0xa2, 0xd2, 0x74,
        0x16, 0xd5, 0xf1, 0x84, 0xdf, 0x9c, 0x25, 0x9a, 0x7c, 0x79
    };
    std::vector<uint8_t> computed_hmac = hmac_sha1(key, msg);
    if(debug){

        if (computed_hmac == expected_hmac) {
            std::cerr << "PASSED: HMAC-SHA1 implementation is correct." << std::endl;
        } else {
            std::cerr << "FAILED: HMAC-SHA1 implementation is incorrect." << std::endl;
        }
    }
}

void test_totp() {
    if(debug)
        std::cerr << "\n--- Testing Part 3: T-OTP ---" << std::endl;
    std::string secret;
    int64_t time_step1;

    std::cin >> secret;
    std::cin >> time_step1;

    if( time_step1 == -1) {
      // Read current time
      time_step1 = getCurrentTimeStep();
    }

    std::string generated1 = generate_totp(secret, time_step1);
    std::cout << generated1 << std::endl;
}

int main() {
    if(debug){
        test_sha1();
        test_hmac();
    }
    test_totp();
    return 0;
}
